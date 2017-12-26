/*
ID: deathkn2
PROG: barn1
*/

#include <algorithm>
#include <fstream>
#include <functional>
#include <numeric>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

int main()
{
	ifstream input( "barn1.in" );
	int m, s, c; input >> m >> s >> c;
	vi x(c);
	for( int i = c - 1; i >= 0; --i )
		input >> x[i];
	sort( all(x) );
	int result = *max_element( all(x) ) - *min_element( all(x) ) + 1;
	adjacent_difference( all(x), x.begin() );
	x[0] = 1;
	sort( all(x), greater<int>() );
	for( int i = 0; i < min(m, c) - 1; ++i )
		result -= x[i] - 1;
	ofstream output( "barn1.out" );
	output << result << endl;
	return 0;
}