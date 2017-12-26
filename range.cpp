/*
ID: deathkn2
PROG: range
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
typedef vector<string> vs;
int main()
{
	ifstream input( "range.in" );
	int N; input >> N;
	vs M(N + 1); M[N] = string(N + 1, '0');
	vvi A(N + 1, vi(N + 1, 0)); vi squares(N + 1, 0), result;
	for( int i = 0; i < N; ++i )
	{
		input >> M[i]; M[i] += '0';
	}
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
		{
			int k = 0;
			for( ; M[i][j + k] == '1'; ++k )
				A[i][j + k] = k + 1;
			j += k;
		}
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
		{
			int k = 0;
			for( ;M[j + k][i] == '1'; ++k )
				A[j + k][i] = min( A[j + k][i], k + 1 );
			j += k;
		}
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
			if ( A[i][j] )
			{
				int k = 0;
				while( A[i + k][j + k] > k )
					++k;
				++squares[k];
			}
	for( vi::iterator it = --find( ++squares.begin(), squares.end(), 0 ); it != ++squares.begin(); --it )
		if ( result.empty() )
			result.push_back( *it );
		else
			result.push_back( result.back() + *it );
	ofstream output( "range.out" );
	for( int i = result.size() - 1, j = 2; i >= 0; --i, ++j )
		output << j << ' ' << result[i] << endl;
	return 0;
}