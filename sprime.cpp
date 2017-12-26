/*
ID: deathkn2
PROG: sprime
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define all(x) (x).begin(), (x).end()

vi primes;
inline bool testPrime( int x )
{
	if ( !binary_search( all(primes), x ) )
		for( vi::iterator it = primes.begin(); it != primes.end() && *it * *it <= x; ++it )
			if ( x % *it == 0 ) return false;
	return true;
}

int main()
{
	ifstream input( "sprime.in" );
	int n; input >> n;
	vi a, b; a.reserve( 1000 ); b.reserve( 1000 );
	a.push_back( 2 );
	a.push_back( 3 );
	a.push_back( 5 );
	a.push_back( 7 );
	primes.reserve( 1229 );
	primes.push_back( 2 );
	primes.push_back( 3 );
	for( int i = primes.back() + 2; i < 10000; i += 2 )
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
	for( int i = 1; i < n; i++ )
	{
		for( vi::iterator it = a.begin(); it != a.end(); ++ it )
		{
			int z = *it * 10 + 1;
			if ( testPrime(z) ) b.push_back( z ); z += 2;
			if ( testPrime(z) ) b.push_back( z ); z += 4;
			if ( testPrime(z) ) b.push_back( z ); z += 2;
			if ( testPrime(z) ) b.push_back( z );
		}
		a.clear(); a.swap( b );
	}
	ofstream output( "sprime.out" );
	for( vi::iterator it = a.begin(); it != a.end(); ++ it )
		output << *it << endl;
	return 0;
}