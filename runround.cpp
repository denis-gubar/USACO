/*
ID: deathkn2
PROG: runround
*/
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
int calcDigits( int x )
{
	int result = 0;
	while( x )
	{
		x /= 10; ++result;
	}
	return result;
}
bool test( vi digits )
{
	int n = digits.size(), j = 0;
	vi f(n, 0);
	for( int i = 0; i < n; ++i )
		if ( f[j] ) return false;
		else
		{
			f[j] = 1;
			j = (digits[j] + j) % n;
		}
	return !j;
}
vi calc( int n )
{
	vi result;
	vi a; a.reserve( 8 );
	for( int i = 1; i <= 9; ++i )
		if ( i % n ) a.push_back( i );
	int k = a.size();
	set<int> cached;
	do
	{
		int hash = 0;
		for( int i = 0; i < n; ++i )
			hash = hash * 10 + a[i];
		if ( cached.insert( hash ).second && accumulate( a.begin(), a.begin() + n, 0 ) % n == 0 && test( vi(a.begin(), a.begin() + n ) ) )
			result.push_back( hash );
	} while( next_permutation( all(a) ) );
	return result;
}
int main()
{
	ifstream input( "runround.in" );
	int n, result; input >> n;
	vi z; z.push_back( 1 ); z.push_back( 2 );
	ofstream output( "runround.out" );	
	if ( n == 9 ) result = 13;
	else if ( n < 9 ) result = n + 1;
	else
	{
		vi A = calc( calcDigits( n ) );
		vi::iterator it = lower_bound( all(A), n + 1 );
		if ( it != A.end() )
			result = *it;
		else
			result = calc( calcDigits( n + 1 ) )[0];
	}
	output << result << endl;
	return 0;
}