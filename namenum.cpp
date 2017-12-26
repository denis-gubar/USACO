/*
ID: deathkn2
PROG: namenum
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<string> vs;
int main()
{
	string s2 = "ABC";
	string s3 = "DEF";
	string s4 = "GHI";
	string s5 = "JKL";
	string s6 = "MNO";
	string s7 = "PRS";
	string s8 = "TUV";
	string s9 = "WXY";
	ifstream input( "namenum.in" );
	string s; input >> s; int n = s.size();
	ifstream dictionary ( "dict.txt" );
	vs result; result.reserve( 5000 );
	while( !dictionary.eof() )
	{
		string t; dictionary >> t;
		if ( t.size() == n )
		{
			bool flag = true;
			for( int i = 0; flag && i < n; ++i )
				switch( s[i] )
				{
					case '2':
						flag = s2.find( t[i] ) != string::npos;
						break;
					case '3':
						flag = s3.find( t[i] ) != string::npos;
						break;
					case '4':
						flag = s4.find( t[i] ) != string::npos;
						break;
					case '5':
						flag = s5.find( t[i] ) != string::npos;
						break;
					case '6':
						flag = s6.find( t[i] ) != string::npos;
						break;
					case '7':
						flag = s7.find( t[i] ) != string::npos;
						break;
					case '8':
						flag = s8.find( t[i] ) != string::npos;
						break;
					case '9':
						flag = s9.find( t[i] ) != string::npos;
						break;
					default:
						flag = false;
						break;
				}
			if ( flag )
				result.push_back( t );
		}
	}
	sort( all(result) );
	ofstream output( "namenum.out" );
	if ( result.empty() )
		output << "NONE" << endl;
	for( vs::iterator it = result.begin(); it != result.end(); ++it )
		output << *it << endl;
	return 0;
}