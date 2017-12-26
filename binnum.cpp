/*
ID: deathkn2
PROG: binnum
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
int main()
{
	ifstream input( "binnum.in" );
	int A; input >> A;
	vi result;
	while( A )
	{
		result.push_back( A % 2 );
		A /= 2;
	}
	if ( result.empty() ) result.push_back( 0 );
	ofstream output( "binnum.out" );
	forad(i, result)
		output << result[i];
	output << endl;
	return 0;
}