/*
ID: deathkn2
PROG: humble
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long lint;
typedef vector<lint> vl;
#define all(v) (v).begin(), (v).end()
int main()
{
	ifstream input( "humble.in" );
	unsigned m, n; input >> m >> n;
	vl a(m + 2), M; M.reserve( 4 * n );
	for( unsigned i = 0; i < m; ++i )
		input >> a[i];
	a[m] = unsigned(-1) >> 1; a[m + 1] = 1;
	sort( all(a) );
	unsigned z = 0;
	lint L = 1;
	while( M.size() < n )
	{
		int l = M.size();
		for( int i = l - 1; i >= 0 && M[i] * a[z] >= L; --i )
			for( unsigned j = 0; j <= z && M[i] >= a[j] && M[i] * a[j] < a[1] * L; j++ )
				if ( M[i] * a[j] >= L )
					M.push_back( M[i] * a[j] );
		while( a[z + 1] < a[1] * L && z < m )
			M.push_back( a[++z] );
		sort( M.begin() + l, M.end() );
		M.erase( unique( M.begin() + l, M.end() ), M.end() );
		L *= a[1];
	}
	ofstream output( "humble.out" );
	output << M[n - 1] << endl;
	return 0;
}