/*
ID: deathkn2
PROG: plates
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
#define all(v) (v).begin(), (v).end()
int main()
{
	ifstream input( "plates.in" );
	int n; input >> n;
	vi A(n + 1, 0), B(n + 1, 0);
	for( int i = 1; i <= n; ++i )
		input >> A[i];
	for( int i = 1; i <= n; ++i )
	{
		for( int j = 0; j < i; ++j )
			if ( B[i] < B[j] && A[i] < A[j] ) B[i] = B[j];
		++B[i];
	}
	ofstream output( "plates.out" );
	output << *max_element( all(B) ) << endl;
	return 0;
}