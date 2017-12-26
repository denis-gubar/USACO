/*
ID: deathkn2
PROG: beads
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input( "beads.in" );
	int n; input >> n;
	string s; s.reserve( n ); input >> s;
	ofstream output( "beads.out" );
	if ( s.find( 'b' ) == string::npos || s.find( 'r' ) == string::npos )
	{
		output << n << endl;
		return 0;
	}
	int result = 2;
	for( int i = n; i > 0; --i )
	{
		int a = s.find_first_of( "br" );
		int b = s[a] == 'b' ? s.find( 'r' ) : s.find( 'b' );
		int c = s.find_last_of( "br" );
		int d = s[c] == 'b' ? s.rfind( 'r' ) : s.rfind( 'b' );
		int e = b + n - d - 1;
		result = max( result, e );		
		rotate( s.begin(), s.begin() + 1, s.end() );
	}
	result = min( result, n );
	output << result << endl;
	return 0;
}