/*
ID: deathkn2
PROG: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input( "ride.in" );
	string a, b;
	input >> a >> b;
	int x = 1, y = 1;
	for( string::iterator it = a.begin(); it != a.end(); ++it )
		x *= *it - 'A' + 1;
	for( string::iterator it = b.begin(); it != b.end(); ++it )
		y *= *it - 'A' + 1;	
	ofstream output( "ride.out" );
	output << ((x % 47 == y % 47) ? "GO" : "STAY") << endl;
	return 0;
}