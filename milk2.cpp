/*
ID: deathkn2
PROG: milk2
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
int main()
{
	ifstream input( "milk2.in" );
	int n; input >> n;
	vi a(n), b(n), c(2 * n);
	for( int i = 0; i < n; ++i )
	{
		input >> a[i] >> b[i];
		c[i] = a[i]; c[i + n] = b[i];
	}
	sort( all(c) );
	c.erase( unique( all(c) ), c.end() );
	int m = c.size(); vi f(m, 0);
	for( int i = 0; i < n; ++i )
		for( vi::iterator it = lower_bound( all(c), a[i] ); *it < b[i]; ++it )
			f[distance( c.begin(), it )] = 1;
	int Max = 0, Min = 0;
	int k = 0;
	while( k < m - 1 )
	{
		int j = k;
		while( f[j] )
			++j;
		Max = max( Max, c[j] - c[k] );
		k = max(j, k + 1);
	}
	k = 0;
	while( k < m - 1 )
	{
		int j = k;
		while( !f[j] )
			++j;
		Min = max( Min, c[j] - c[k] );
		k = max(j, k + 1);
	}
	ofstream output( "milk2.out" );	
	output << Max << ' ' << Min << endl;
	return 0;
}