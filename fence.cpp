/*
ID: deathkn2
PROG: fence
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
typedef vector<short> vi;
typedef vector<vi> vvi;
#define all(v) (v).begin(), (v).end()
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
void dfs( int x, vvi& E, vvi& cycles )
{
	cycles.back().push_back( x );
	bool flag = false;
	for( int i = 1; i < 501; ++i )
		if ( E[x][i] )
		{
			if ( flag )
			{
				if ( cycles.size() > 1 )
					cycles.back().pop_back();
				cycles.push_back( vi(1, x) );
			}
			--E[x][i]; --E[i][x];
			dfs( i, E, cycles );
			flag = true;
		}
}
int main()
{
	ifstream input( "fence.in" );
	int f; input >> f;
	vi degree(501, 0);
	vvi E(501, degree), cycles;
	cycles.push_back( vi() );
	for( int i = 0; i < f; ++i )
	{
		int a, b; input >> a >> b;
		++E[a][b]; ++E[b][a];
	}
	int start = 501;
	for( int i = 1; i < 501; ++i )
	{
		degree[i] = accumulate( all(E[i]), 0 );
		if ( degree[i] % 2 )
			start = min(start, i);
	}
	if ( start == 501 )
		for( start = 1; !degree[start]; ++start );
	dfs( start, E, cycles );
	if ( cycles.size() > 1 )
		cycles.back().pop_back();
	ofstream output( "fence.out" );
	vi result(cycles[0]);
	for( int i = 1; i < cycles.size(); ++i )
	{
		vi::iterator Last;
		for( vi::iterator it = result.begin(); it != result.end(); it = find( it + 1, result.end(), cycles[i][0] ) )
			Last = it;
		result.insert( Last, all(cycles[i]) );
	}
	copy( all(result), ostream_iterator<int>( output, "\n" ) );
	return 0;
}