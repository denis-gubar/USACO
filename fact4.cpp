/*
ID: deathkn2
PROG: fact4
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
int main()
{
	ifstream input( "fact4.in" );
	int n; input >> n;
	int x = 1;
	for( int i = 2; i <= n; ++i )
	{
		x *= i;
		while( x % 10 == 0 )
			x /= 10;
		x %= 1000;
	}
	ofstream output( "fact4.out" );
	output << x % 10 << endl;
	return 0;
}