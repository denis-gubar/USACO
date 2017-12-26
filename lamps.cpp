/*
ID: deathkn2
PROG: lamps
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
int main()
{
	ifstream input( "lamps.in" );
	int N, C; input >> N >> C;
	vi mask(6, 2);
	ofstream output( "lamps.out" );
	while( true )
	{
		int x; input >> x;
		if ( x == -1 ) break;
		x = 5 - (x - 1) % 6;
		if ( mask[x] == 0 )
		{
			output << "IMPOSSIBLE" << endl;
			return 0;
		}
		mask[x] = 1;
	}
	while( true )
	{
		int x; input >> x;
		if ( x == -1 ) break;
		x = 5 - (x - 1) % 6;
		if ( mask[x] == 1 )
		{
			output << "IMPOSSIBLE" << endl;
			return 0;
		}
		mask[x] = 0;
	}
	set<int> result; result.insert( 077 );
	for( int i = 0; i < C; ++i )
	{
		set<int> next_result;
		for( set<int>::iterator it = result.begin(); it != result.end(); ++it )
		{
			next_result.insert( *it ^ 077 );
			next_result.insert( *it ^ 052 );
			next_result.insert( *it ^ 025 );
			next_result.insert( *it ^ 044 );
		}
		next_result.swap( result );
	}
	int count = 0;
	for( set<int>::iterator it = result.begin(); it != result.end(); ++it )
	{
		string s;
		bool flag = true;
		for( int i = 5; i >= 0; --i )
		{
			int k = (*it & (1 << i)) > 0;
			if ( k + mask[i] == 1 )
			{
				flag = false; break;
			}
			s += k + '0';
		}
		if ( flag )
		{
			for( int i = 0; i < N / 6; ++i )
				output << s;
			output << s.substr( 0, N % 6 ) << endl;
			++count;
		}
	}
	if ( !count )
		output << "IMPOSSIBLE" << endl;
	return 0;
}