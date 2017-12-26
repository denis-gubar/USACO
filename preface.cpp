/*
ID: deathkn2
PROG: preface
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
char chars[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int result[] = {0, 0, 0, 0, 0, 0, 0};

inline void calc( int x )
{
	switch( x % 10 )
	{
		case 1:
		case 4:
		case 6:
		case 9:
			++result[0];
			break;
		case 2:
		case 7:
			result[0] += 2;
			break;
		case 3:
		case 8:
			result[0] += 3;
			break;
	}
	if ( x % 10 >= 4 && x % 10 <= 8 )
		++result[1];
	if ( x % 10 == 9 )
		++result[2];
	x /= 10;
	switch( x % 10 )
	{
		case 1:
		case 4:
		case 6:
		case 9:
			++result[2];
			break;
		case 2:
		case 7:
			result[2] += 2;
			break;
		case 3:
		case 8:
			result[2] += 3;
			break;
	}
	if ( x % 10 >= 4 && x % 10 <= 8 )
		++result[3];
	if ( x % 10 == 9 )
		++result[4];
	x /= 10;
	switch( x % 10 )
	{
		case 1:
		case 4:
		case 6:
		case 9:
			++result[4];
			break;
		case 2:
		case 7:
			result[4] += 2;
			break;
		case 3:
		case 8:
			result[4] += 3;
			break;
	}
	if ( x % 10 >= 4 && x % 10 <= 8 )
		++result[5];
	++x; x /= 10;
	result[6] += x;
}

int main()
{
	ifstream input( "preface.in" );
	int n; input >> n;
	for( int i = 1; i <= n; i++ )
		calc( i );
	ofstream output( "preface.out" );	
	for( int i = 0; i < 7; i++ )
		if ( result[i] )
			output << chars[i] << ' ' << result[i] << endl;
	return 0;
}