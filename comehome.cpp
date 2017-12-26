/*
ID: deathkn2
PROG: comehome
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
int main()
{
	ifstream input( "comehome.in" );
	int p; input >> p;
	vi a(p), b(p), l(p);
	for( int i = 0; i < p; ++i )
	{
		char first, second;
		input >> first >> second >> l[i];
		a[i] = ('A' <= first && first <= 'Z') ? first - 'A' : first - 'a' + 26;
		b[i] = ('A' <= second && second <= 'Z') ? second - 'A' : second - 'a' + 26;
	}
	vi f(52, numeric_limits<int>::max()); f[25] = 0;
	queue<int> q; q.push( 25 );
	while( !q.empty() )
	{		
		int k = q.front(); q.pop();
		vi needToVisit( 52, 0 );
		for( int i = 0; i < p; ++i )
		{
			if ( a[i] == k && f[b[i]] > f[k] + l[i] )
			{
				needToVisit[b[i]] = 1;
				f[b[i]] = f[k] + l[i];
			}
			if ( b[i] == k && f[a[i]] > f[k] + l[i] )
			{
				needToVisit[a[i]] = 1;
				f[a[i]] = f[k] + l[i];
			}
		}
		needToVisit[k] = 0;
		for( int i = 0; i < 52; ++i )
			if ( needToVisit[i] )
				q.push( i );
	}
	vi::iterator it = min_element( f.begin(), f.begin() + 25 );
	ofstream output( "comehome.out" );	
	output << char(distance( f.begin(), it ) + 'A') << ' ' << *it << endl;
	return 0;
}