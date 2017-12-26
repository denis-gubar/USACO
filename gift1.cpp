/*
ID: deathkn2
PROG: gift1
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;

int main()
{
	ifstream input( "gift1.in" );
	int n; input >> n;
	vs names(n); map<string, int> balance;
	for( vs::iterator it = names.begin(); it != names.end(); ++it )
	{
		input >> *it;
		balance[*it] = 0;
	}
	while( !input.eof() )
	{
		string s; input >> s;
		int sum, k; input >> sum >> k;
		int gift = k > 0 ? sum / k : 0;
		for( int i = k; i > 0; --i )
		{
			string t; input >> t;
			balance[t] += gift;
		}
		balance[s] -= gift * k;			
	}
	ofstream output( "gift1.out" );
	for( vs::iterator it = names.begin(); it != names.end(); ++it )
		output << *it << ' ' << balance[*it] << endl;
	return 0;
}