/*
ID: deathkn2
PROG: numtri
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;

int main()
{
	ifstream input( "numtri.in" );
	int n; input >> n;
	vi b(n, 0), c(n, 0);
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j <= i; ++j )
		{
			int a; input >> a;
			c[j] = max( b[j], j ? b[j - 1] : 0 ) + a;
		}
		c.swap( b );
	}
	ofstream output( "numtri.out" );
	output << *max_element( all(b) ) << endl;
	return 0;
}