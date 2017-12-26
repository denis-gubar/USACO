/*
ID: deathkn2
PROG: rect1
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <numeric>
#include <list>
#include <set>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;

struct Rectangle
{
	int x1, y1, x2, y2, color;
	Rectangle( int x1, int y1, int x2, int y2, int color ) : x1(x1), y1(y1), x2(x2), y2(y2), color(color) {}
	Rectangle() {}

	int square() const
	{
		return (x2 - x1) * (y2 - y1);
	}
	bool isIntersect( Rectangle& A ) const
	{
		return (x1 - A.x2 + 1) * (x2 - 1 - A.x1) <= 0 && (y1 - A.y2 + 1) * (y2 - 1 - A.y1) <= 0;
	}
	list<Rectangle> intersect( Rectangle& A ) const
	{
		list<Rectangle> result;
		if ( isIntersect( A ) )
		{
			set<int> x, y;
			x.insert( A.x1 ); x.insert( A.x2 ); x.insert( x1 ); x.insert( x2 );
			y.insert( A.y1 ); y.insert( A.y2 ); y.insert( y1 ); y.insert( y2 );
			vi X( all(x) ), Y( all(y) );
			for( vi::iterator itx = X.begin(); itx + 1 != X.end(); ++itx )
				for( vi::iterator ity = Y.begin(); ity + 1 != Y.end(); ++ity )
				{
					Rectangle B( *itx, *ity, *(itx + 1), *(ity + 1), A.color );
					if ( B.square() && A.isIntersect( B ) && !isIntersect( B ) )
						result.push_back( B );
				}
		}
		else result.push_back( A );
		return result;
	}
};

bool operator <( const Rectangle& a, const Rectangle& b )
{
	if ( a.x1 != b.x1 ) return a.x1 < b.x1;
	return a.y1 < b.y1;
}

int main()
{
	ifstream input( "rect1.in" );
	int a, b, n; input >> a >> b >> n;
	list<Rectangle> L;
	L.push_back( Rectangle( 0, 0, a, b, 1 ) );
	for( int i = n; i > 0; --i )
	{
		Rectangle R;
		input >> R.x1 >> R.y1 >> R.x2 >> R.y2 >> R.color;
		for( list<Rectangle>::iterator it = L.begin(); it != L.end(); )
		{
			list<Rectangle> L2 = R.intersect( *it );
			it = L.erase( it );
			L.splice( L.begin(), L2 );
		}
		L.push_back( R );
	}
	vi colors(2501, 0);
	for( list<Rectangle>::iterator it = L.begin(); it != L.end(); ++it )
		colors[it->color] += it->square();
	ofstream output( "rect1.out" );
	for( short i = 1; i <= 2500; ++i )
		if ( colors[i] )
			output << i << ' ' << colors[i] << endl;
	return 0;
}