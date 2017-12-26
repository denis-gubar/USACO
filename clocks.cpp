/*
ID: deathkn2
PROG: clocks
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef vector<int> vi;
inline int encode( vi& dials )
{
	int result = 0;
	for( int i = 0; i < 9; ++i )
		result = (result << 2) | dials[i];
	return result;
}
int moves[] = {0,
	0x14500,
	0x15000,
	 0x5140,
	0x10410,
	 0x4544,
	 0x1041,
	  0x514,
	   0x15,
	  0x145};
int main()
{
	ifstream input( "clocks.in" );
	vi dials(9);
	for( int i = 0; i < 9; ++i )
	{
		int x; input >> x;
		dials[i] = x % 12 / 3;
	}	
	vi f(1 << 18, -1); int finish = encode( dials );
	queue<int> q; q.push( finish );
	while( !q.empty() )
	{
		int k = q.front(); q.pop();
		if ( !k ) break;
		for( int i = 1; i <= 9; ++i )
		{
			int hash = 0;
			for( int a = 0x30000; a; a >>= 2 )
				hash |= ((k & a) + (moves[i] & a)) & a;
			if ( f[hash] < 0 )
			{
				f[hash] = i; q.push( hash );
			}
		}
	}
	vi result;
	for( int i = 0; i != finish;  )
	{
		result.push_back( f[i] );
		int hash = 0;
		for( int a = 0x30000; a; a >>= 2 )
			hash |= ((i & a) + 3 * (moves[f[i]] & a)) & a;
		i = hash;
	}
	ofstream output( "clocks.out" );	
	for( int i = result.size() - 1; i > 0; --i )
		output << result[i] << ' ';
	output << result[0] << endl;
	return 0;
}