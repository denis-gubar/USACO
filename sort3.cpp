/*
ID: deathkn2
PROG: sort3
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
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(v) (v).begin(), (v).end()
int main()
{
	ifstream input( "sort3.in" );
	int n; input >> n; vi A(n);
	copy( istream_iterator<int>( input ), istream_iterator<int>(), A.begin() );
	vi a(4, 0); vvi b(4, vi(4, 0));
	for( int i = 0; i < n; ++i )
		++a[A[i]];
	for( int i = 0; i < a[1]; ++i )
		if ( A[i] != 1 )
			++b[1][A[i]];
	for( int i = a[1]; i < a[1] + a[2]; ++i )
		if ( A[i] != 2 )
			++b[2][A[i]];
	for( int i = a[1] + a[2]; i < n; ++i )
		if ( A[i] != 3 )
			++b[3][A[i]];
	int result = 0;
	for( int i = 1; i < 4; ++i )
		for( int j = i + 1; j < 4; ++j )
		{
			int m = min(b[i][j], b[j][i] );
			b[i][j] -= m; b[j][i] -= m;
			result += m;
		}
	result += 2 * (b[1][2] + b[2][1] + b[1][3] + b[3][1] + b[2][3] + b[3][2]) / 3;
	ofstream output( "sort3.out" );
	output << result << endl;
	return 0;
}