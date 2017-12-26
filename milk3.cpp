/*
ID: deathkn2
PROG: milk3
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
inline int encode( int a, int b, int c )
{
	return (a * 21 + b) * 21 + c;
}
inline void decode( int x, int& a, int& b, int& c )
{
	a = x / 21 / 21;
	b = x / 21 % 21;
	c = x % 21;
}
int main()
{
	ifstream input( "milk3.in" );
	int A, B, C; input >> A >> B >> C;
	vi f(C + 1, 0), result;
	vi s(21 * 21 * 21, 0);
	int hash = encode( 0, 0, C );
	s[hash] = 1;
	queue<int> q; q.push( hash );
	while( !q.empty() )
	{
		hash = q.front(); q.pop();
		int a, b, c, x, y, z, k;
		decode( hash, a, b, c );
		if ( !a ) f[c] = 1;
		x = min(a + b, A); y = a + b - x; z = c; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
		x = min(a + c, A); y = b; z = a + c - x; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
		x = a; y = min(b + c, B); z = b + c - y; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
		y = min(a + b, B); x = a + b - y; z = c; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
		z = min(a + c, C); x = a + c - z; y = b; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
		z = min(b + c, C); y = b + c - z; x = a; k = encode( x, y, z );
		if ( !s[k] ) { s[k] = 1; q.push( k ); }
	}
	ofstream output( "milk3.out" );
	for( int i = 0; i <= C; ++i )
		if ( f[i] ) result.push_back( i );
	for( int i = 0; i < result.size() - 1; ++i )
		output << result[i] << ' ';
	output << result.back() << endl;
	return 0;
}