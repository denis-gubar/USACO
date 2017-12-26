/*
ID: deathkn2
PROG: contact
*/

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;

struct Answer
{
	int n, x, freq;
	Answer() {};
	Answer( int n, int x, int freq ) : n(n), x(x), freq(freq) {}
	string value()
	{
		string result;
		int y = x;
		for( int i = 0; i < n; i++ )
		{
			result += char('0' + y % 2);
			y /= 2;
		}
		reverse( all(result) );
		return result;
	}
};

struct comp: binary_function<bool, Answer, Answer>
{
	bool operator() ( const Answer& a, const Answer& b ) const
	{
		if ( a.freq != b.freq ) return a.freq > b.freq;
		if ( a.n != b.n ) return a.n < b.n;
		return a.x < b.x;
	}
};

int main()
{
	ifstream input( "contact.in" );
	size_t a, b, n; input >> a >> b >> n;
	vi s; s.reserve(200000);
	while( !input.eof() )
	{
		string t; input >> t;
		for( string::iterator it = t.begin(); it != t.end(); ++it )
			s.push_back( *it - '0' );
	}
	vvi M(b + 1);
	for( int i = a; i <= min(b, s.size()); ++i )
	{
		int maskI = (1 << i) - 1, mask = 0;
		M[i] = vi( maskI + 1, 0 );
		for( int j = 0; j < i - 1; j++ )
			mask = (mask << 1) | s[j];
		for( int j = i - 1; j < s.size(); ++j )
		{
			mask = ((mask << 1) | s[j]) & maskI;
			++M[i][mask];
		}
	}
	vector<Answer> answers;
	for( int i = a; i <= min(b, s.size()); ++i )
		for( int j = 0; j < M[i].size(); ++j )
			answers.push_back( Answer( i, j, M[i][j] ) );
	sort( all(answers), comp() );
	ofstream output( "contact.out" );	
	int prev_freq = -1;
	for( int i = 0, j = 0, results; i < answers.size() && answers[i].freq; ++i )
	{
		if ( answers[i].freq != prev_freq )
		{
			++j; if ( j > n ) break;
			if ( prev_freq > 0 )
				output << endl;
			results = 1; prev_freq = answers[i].freq;
			output << prev_freq << endl;
		} else ++results;
		if ( results > 1 )
		{
			if ( results % 6 == 1 )
				output << endl;
			else
				output << ' ';
		}
		output << answers[i].value();
	}
	if ( prev_freq > 0 )
		output << endl;
	return 0;
}