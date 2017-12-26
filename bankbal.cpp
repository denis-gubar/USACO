/*
ID: deathkn2
PROG: bankbal
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
typedef long long lint;
typedef vector<lint> vl;
int main()
{
	ifstream input( "bankbal.in" );
	lint n; input >> n;
	vl balance(4, 0);
	string names[] = {"Alice", "Betsy", "Corinne", "Debra"};
	for( int i = 0; i < n; ++i )
	{
		string name; lint delta;
		input >> name >> delta;
		balance[name[0] - 'A'] += delta;
	}
	ofstream output( "bankbal.out" );
	for( int i = 0; i < 4; ++i )
		output << names[i] << ' ' << balance[i] << endl;
	return 0;
}