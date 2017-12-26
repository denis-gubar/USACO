/*
ID: deathkn2
PROG: kimbits
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lint> vl;
typedef vector<vl> vvl;
lint C( lint n, lint k )
{
	static const int N = 50;
	static bool isCached = false;
	static vvl cache = vvl(N + 1, vl(N + 1, 0));
	if ( !isCached )
	{
		for( int i = 0; i <= N; i++ )
			cache[i][0] = cache[i][i] = 1;
		for( int i = 1; i <= N; i++ )
			for( int j = 1; j < i; j++ )
				cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}
int main()
{
	ifstream input( "kimbits.in" );
	lint N, L, I; input >> N >> L >> I;
	vl result(N + 1, 0);
	vvl M(N + 1, vl(N + 1, 0));
	for( int i = 0; i <= N; ++i )
	{
		M[i][0] = 1;
		for( int j = 1; j <= i; ++j )
			M[i][j] = M[i][j - 1] + C( i, j );
		for( int j = i + 1; j <= N; ++j )
			M[i][j] = M[i][i];
	}
	int k = N;
	while( I > 1 )
	{
		while( k >= 0 && M[k][L] >= I ) --k;
		result[k + 1] = 1;
		I -= M[k][L]; --L;
	}
	ofstream output( "kimbits.out" );
	for( int i = result.size() - 1; i > 0; --i )
		output << result[i];
	output << endl;
	return 0;
}