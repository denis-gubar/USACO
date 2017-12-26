/*
ID: deathkn2
PROG: clock
*/

#include <fstream>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

string numbers[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
		"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string numbers2[] = {"", "", "twenty", "thirty", "forty"};

template <typename T> vector<T> Split( string s, string delimeters = " " )
{
	vector<T> result; s += delimeters[0];
	for( int i = 0, prev = 0; i < s.size(); i++ )
		if ( delimeters.find( s[i] ) != -1 )
		{
			if ( prev < i )
			{
				istringstream S( s.substr( prev, i - prev ) );
				T current; S >> current; 
				if ( S.rdstate() ^ ios::failbit )
					result.push_back( current );
			}
			prev = i + 1;
		}
	return result;
}
int main()
{
	ifstream input( "clock.in" );
	string s; input >> s;
	vi x = Split<int>( s, ":" );
	string result;
	switch ( x[1] )
	{
		case 0:
			result = numbers[x[0]] + " o'clock";
			break;
		case 15:
			result = "quarter past " + numbers[x[0]];
			break;
		case 45:
			result = "quarter to " + numbers[x[0] == 12 ? 1 : x[0] + 1];
			break;
		default:
			if ( x[1] > 45 )
				result = numbers[60 - x[1]] + " to " + numbers[x[0] == 12 ? 1 : x[0] + 1];
			else if ( x[1] < 20 )
				result = numbers[x[0]] +  " " + numbers[x[1]];
			else
				result = numbers[x[0]] +  " " + numbers2[x[1] / 10] + (x[1] % 10 ? "-" + numbers[x[1] % 10] : "");
			break;
	}
	result[0] = toupper(result[0]);
	ofstream output( "clock.out" );
	output << result << endl;
	return 0;
}