/*
ID: deathkn2
PROG: nocows
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
int C( int n, int k )
{
	static const int N = 100;
	static bool isCached = false;
	static vvi cache = vvi(N + 1, vi(N + 1));
	if ( !isCached )
	{
		for( int i = 0; i <= N; ++i )
			cache[i][0] = cache[i][i] = 1;
		for( int i = 1; i <= N; ++i )
			for( int j = 1; j < i; ++j )
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % 9901;
	}
	isCached = true;
	return n >= k && k >= 0 && n <= N ? cache[n][k] : 0;
}
int main()
{
	int N, K, result = 0;
	ifstream input( "nocows.in" );
	input >> N >> K;
	vvi A(N + 1, vi(N + 1));
	A[1][1] = 1;
	for( int k = 2; k <= K; ++k )
	{
		vvi B(N + 1, vi(N + 1));
		for( int n = 3; n <= N; n += 2 )
			for( int a = 2; a <= n; a += 2 )
			{
				for( int x = a / 2; x <= n - a; ++x )
					B[n][a] += A[n - a][x] * C( x, a / 2 );
				B[n][a] %= 9901;
			}
		A.swap( B );
	}
	ofstream output( "nocows.out" );
	result = accumulate( all(A[N]), 0 ) % 9901;
	output << result << endl;	
	return 0;
}