/*
ID: deathkn2
PROG: calfflac
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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
int main()
{
	ifstream input( "calfflac.in" );
	char buffer[21000];
	input.get( &buffer[0], 20001, 0 );
	string text(buffer), words;
	words.reserve( text.size() );
	vi A; A.reserve( 21000 );
	for( int i = 0; i < text.size(); ++i )
		if ( isalpha( text[i] ) )
		{
			words += tolower( text[i] );
			A.push_back( i );
		}
	vi B( A.size() * 2, 2001 );
	int result = -1, start = 0;
	ofstream output( "calfflac.out" );
	if ( A.empty() )
	{
		output << "0" << endl;
		return 0;
	}
	for( int i = 0; i < words.size() - result; ++i )
	{
		for( int j = min( (int) words.size(), i + 2000 ) - 1; j > i + result; --j )
			if ( words[i] == words[j] )
			{
				if ( B[i + j] > j - i )
				{
					int a = i, b = j;
					while( a < b && words[a] == words[b] )
					{
						++a; --b;
					}
					B[i + j] = b - a;
					if ( a >= b )
					{
						result = j - i; start = i;
						break;
					}
				}
			}
			else if ( B[i + j] < j - i )
				B[i + j] = j - i ;
	}
	output << result + 1 << endl;
	output << text.substr( A[start], A[start + result] - A[start] + 1 ) << endl;
	return 0;
}