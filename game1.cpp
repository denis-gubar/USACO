/*
ID: deathkn2
PROG: game1
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
vvi cache; vi A;
int calc( int a, int b )
{
	int& result = cache[a][b];
	if ( !result )
	{
		if ( a == b ) result = A[a];
		else
			result = max( A[a] - calc( a + 1, b ), A[b] - calc( a, b - 1 ) );
	}
	return result;
}
int main()
{
	ifstream input( "game1.in" );
	int N; input >> N;
	A = vi(N); copy( istream_iterator<int>( input ), istream_iterator<int>(), A.begin() );
	cache = vvi(N, vi(N, 0));
	int x = calc( 0, N - 1 );
	int total = accumulate( all(A), 0 );
	int a = (total + x) / 2;
	int b = total - a;
	if ( N % 2 == 0 && a < b )
		swap( a, b );
	ofstream output( "game1.out" );
	output << a << ' ' << b << endl;
	return 0;
}