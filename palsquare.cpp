/*
ID: deathkn2
PROG: palsquare
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define forad(i,v) for(int i = (v).size() - 1; i >= 0; i--)
#define all(v) (v).begin(), (v).end()
vi calc( int x, int n )
{
	vi result;
	while( x )
	{
		result.push_back( x % n ); x /= n;
	}
	return result;
}
int main()
{
	ifstream input( "palsquare.in" );
	ofstream output( "palsquare.out" );
	int n; input >> n;
	char digits[] = "0123456789ABCDEFGHIJ";
	for( int i = 1; i <= 300; ++i )
	{
		vi a = calc( i * i, n ), b(a);
		reverse( all(b) );
		if ( a == b )
		{
			b = calc( i, n );
			forad(j, b)
				output << digits[b[j]];
			output << ' ';
			forad(j, a)
				output << digits[a[j]];
			output << endl;
		}
	}
	return 0;
}