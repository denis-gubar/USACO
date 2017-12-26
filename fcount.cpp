/*
ID: deathkn2
PROG: fcount
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
int main()
{
	ifstream input( "fcount.in" );
	int C, F1, F2, D; input >> C >> F1 >> F2 >> D;
	vi eaten(2001, 0);
	for( int i = 0; i < C; ++i )
	{
		int a, b; input >> a >> b;
		for( int i = a; i <= min(b, D); ++i )
			++eaten[i];
	}
	int result = D, left = F2;
	while( left < F1 )
	{
		left += eaten[result];
		if ( left < F1 )
			--result;
	}
	ofstream output( "fcount.out" );
	output << result << endl;
	return 0;
}