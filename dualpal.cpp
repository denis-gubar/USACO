/*
ID: deathkn2
PROG: dualpal
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
vi x;
void convert( int k, int base )
{
	x.clear();
	while( k )
	{
		x.push_back( k % base );
		k /= base;
	}
}
bool isPalindrom()
{
	int i = 0, j = x.size() - 1;
	for( ; i < j; ++i, --j )
		if ( x[i] != x[j] ) return false;
	return true;
}
int main()
{
	ifstream input( "dualpal.in" );
	int N, S; input >> N >> S; x.reserve(100);
	ofstream output( "dualpal.out" );
	for( int i = 0, k = S + 1; i < N; ++k )
	{
		int count = 0;
		for( int base = 2; base <= 10; ++base )
		{
			convert( k, base );
			if ( isPalindrom() )
			{
				++count;
				if ( count == 2 )
				{
					output << k << endl;
					++i;
					break;
				}
			}
		}
	}
	return 0;
}