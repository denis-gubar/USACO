/*
ID: deathkn2
PROG: pprime
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi primes, result;
inline int makePalindrom( int x )
{
	int result = 0;
	while( x )
	{
		result = result * 10 + x % 10;
		x /= 10;
	}
	return result;
}
inline bool isPalindrom( int x )
{
	return x == makePalindrom( x );
}
inline void testPrime( int x, int a, int b )
{
	if ( x < a || x > b ) return;
	if ( !isPalindrom( x ) ) return;
	if ( !binary_search( primes.begin(), primes.end(), x ) )
		for( vi::iterator it = primes.begin(); it != primes.end() && *it * *it <= x; ++it )
			if ( x % *it == 0 ) return;
	result.push_back( x );
}
inline int calc( int x, int k )
{
	x = makePalindrom( x );
	return x - x / k * k;
}
int main()
{
	ifstream input( "pprime.in" );
	int a, b; input >> a >> b;
	primes.reserve( 1229 );	result.reserve( 639 );
	primes.push_back( 2 );
	primes.push_back( 3 );
	for( int i = primes.back() + 2; i * i <= b; i += 2 )
	{
		bool flag = true;
		for( vi::iterator it = primes.begin(); it != primes.end(); ++it )
			if ( i % *it == 0 )
			{
				flag = false;
				break;
			}
		if ( flag )
			primes.push_back( i );
	}
	testPrime( 5, a, b );
	testPrime( 7, a, b );
	testPrime( 11, a, b );
	for( int i = 1; i < 100; ++i )
		testPrime( i * 10 + calc(i, 10), a, b );
	for( int i = 1; i < 1000; ++i )
		testPrime( i * 100 + calc(i, 100), a, b );
	for( int i = 1; i < 10000; ++i )
		testPrime( i * 1000 + calc(i, 1000), a, b );
	sort( result.begin(), result.end() );
	result.erase( unique( result.begin(), result.end() ), result.end() );
	ofstream output( "pprime.out" );
	for( vi::iterator it = result.begin(); it != result.end(); ++it )
		output << *it << endl;
	return 0;
}