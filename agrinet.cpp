/*
ID: deathkn2
PROG: agrinet
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
typedef pair<int, int> pii;
int main()
{
	ifstream input( "agrinet.in" );
	int N; input >> N;
	vvi M(N, vi(N)); vi f(N, 0); f[0] = 1;
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < N; ++j )
			input >> M[i][j];
	int result = 0;
	priority_queue<pii> q;
	for( int i = 1; i < N; ++i )
	{
		q.push( make_pair( -M[0][i], i ) );
		M[0][i] = M[i][0] = 0;
	}
	for( int k = 1; k < N; )
	{
		pii x = q.top(); q.pop();
		if ( !f[x.second] )
		{
			f[x.second] = 1;
			result -= x.first;
			++k;
			for( int i = 0; i < N; ++i )
				if ( M[x.second][i] )
				{
					q.push( make_pair( -M[x.second][i], i ) );
					M[x.second][i] = M[i][x.second] = 0;
				}
		}
	}
	ofstream output( "agrinet.out" );
	output << result << endl;
	return 0;
}