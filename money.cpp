/*
ID: deathkn2
PROG: money
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vl> vvl;
int main()
{
	ifstream input( "money.in" );
	int v, n; input >> v >> n;
	vi coins(v); vvl sum(n + 1, vl(v, 0));
	for( int i = 0; i < v; ++i )
		input >> coins[i];
	sum[0] = vl(v, 1);
	for( int i = 1; i <= n; ++i )
		for( int j = 0; j < v; ++j )
			if ( coins[j] <= i )
				for( int k = j; k < v; ++k )
					sum[i][k] += sum[i - coins[j]][j];
	ofstream output( "money.out" );	
	output << sum[n][v - 1] << endl;
	return 0;
}