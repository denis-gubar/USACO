/*
ID: deathkn2
PROG: frac1
*/

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef pair<int, int> pii;
typedef vector<pii> vpii;

inline int gcd( int a, int b )
{
	while( a && b )
		if ( a > b ) a %= b;
		else b %= a;
	return a + b;
}

struct comp: binary_function<bool, pii, pii>
{
	bool operator() ( const pii& a, const pii& b ) const
	{
		return a.first * b.second < a.second * b.first;
	}
};

int main()
{
	ifstream input( "frac1.in" );
	int n; input >> n;
	ofstream output( "frac1.out" );
	vpii result;
	for( int i = 2; i <= n; ++i )
	{
		for( int j = 1; j < i; j++ )
			if ( gcd(i, j) == 1 )
				result.push_back( make_pair(j, i) );
	}
	result.push_back( make_pair(0, 1) );
	result.push_back( make_pair(1, 1) );
	sort( all(result), comp() );
	for( vpii::iterator it = result.begin(); it != result.end(); ++it )
		output << it->first << '/' << it->second << endl;
	return 0;
}