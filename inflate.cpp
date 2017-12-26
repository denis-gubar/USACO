/*
ID: deathkn2
PROG: inflate
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
int main()
{
	ifstream input( "inflate.in" );
	int m, n; input >> m >> n;
	vi A(m + 1, 0);
	for( int i = 0; i < n; ++i )
	{
		int x, y; input >> x >> y;
		if ( y <= m && A[y] < x ) A[y] = x;
	}
	for( int i = 1; i <= m; ++i )
		for( int j = 0; j < i; ++j )
			if ( A[i - j] + A[j] > A[i] )
				A[i] = A[i - j] + A[j];
	ofstream output( "inflate.out" );
	output << A[m] << endl;
	return 0;
}