/*
ID: deathkn2
PROG: packrec
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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(size_t i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
int bestArea = 40000;
set<pii> result;
struct Point
{
    int x, y, type;
    Point( int x, int y, int type ): x(x), y(y), type(type) {}
    Point(): x(0), y(0), type(0) {}
};
struct Rectangle
{
    int left, top, right, bottom;
    Rectangle( int left, int top, int right, int bottom ): left(left), top(top), right(right), bottom(bottom) {}
    Rectangle(): left(0), top(0), right(0), bottom(0) {}
    bool isIntersect( const Rectangle& other ) const
    {
        return !(left > other.right || right < other.left || top > other.bottom || bottom < other.top);
    }
    int area() const
    {
        return (right - left + 1) * (bottom - top + 1);
    }
};
void calc( const vpii& B, vector<Rectangle> R, vector<Point> P )
{
    int k = R.size();
    fora(i, P)
    {
        Rectangle r;
        switch( P[i].type )
        {
        case 0:
            r = Rectangle( P[i].x, P[i].y, P[i].x + B[k].first - 1, P[i].y + B[k].second - 1 );
            break;
        case 1:
            r = Rectangle( P[i].x, P[i].y - B[k].second + 1, P[i].x + B[k].first - 1, P[i].y );
            break;
        case 2:
            r = Rectangle( P[i].x - B[k].first + 1, P[i].y, P[i].x, P[i].y + B[k].second - 1 );
            break;
        }
        bool flag = true;
        fora(j, R)
            if ( R[j].isIntersect( r ) )
            {
                flag = false; break;
            }                   
        if ( !flag )
            continue;
        vector<Rectangle> NR(R);
        NR.push_back( r );
        Rectangle t(200, 200, 0, 0);
        fora(j, NR)
        {
            t.left = min( t.left, NR[j].left );
            t.top = min( t.top, NR[j].top );
            t.right = max( t.right, NR[j].right );
            t.bottom = max( t.bottom, NR[j].bottom );
        }
        int area = t.area();
        if ( area > bestArea )
            continue;
        if ( k == 3 )
        {
            if ( area < bestArea )
            {
                bestArea = area;
                result.clear();
            }
            int x = t.right - t.left + 1, y = t.bottom - t.top + 1;
            if ( x > y )
                swap( x, y );
            result.insert( make_pair( x, y ) );
            continue;
        }
        vector<Point> TP(P), NP;
        TP.push_back( Point(r.right + 1, r.top, 0) );
        TP.push_back( Point(r.left, r.bottom + 1, 0) );
        TP.push_back( Point(r.right + 1, r.bottom, 1) );
        TP.push_back( Point(r.right, r.bottom + 1, 2) );
        fora(k, TP)
        {
            Rectangle p( TP[k].x, TP[k].y, TP[k].x, TP[k].y );
            flag = true;
            fora(j, R)
                if ( R[j].isIntersect( r ) )
                {
                    flag = false; break;
                }
            if ( flag )
                NP.push_back( TP[k] );
        }
        calc( B, NR, NP );
    }
}
int main()
{
	ifstream input( "packrec.in" );
	ofstream output( "packrec.out" );
    vpii A(4), B(4); vi X(4);
    fora(i, A)
        input >> A[i].first >> A[i].second;    
    fora(i, X)
        X[i] = i;
    do
    {
        for( int i = 0; i < 16; ++i )
        {
            for( int j = 0; j < 4; ++j )
                if ( i & (1 << j) )
                    B[j] = make_pair(A[X[j]].second, A[X[j]].first);
                else
                    B[j] = A[X[j]];
            vector<Rectangle> R;
            R.push_back( Rectangle( 0, 0, B[0].first - 1, B[0].second - 1 ) );
            vector<Point> P;
            P.push_back( Point(R[0].right + 1, R[0].top, 0) );
            P.push_back( Point(R[0].left, R[0].bottom + 1, 0) );
            P.push_back( Point(R[0].right + 1, R[0].bottom, 1) );
            P.push_back( Point(R[0].right, R[0].bottom + 1, 2) );
            calc( B, R, P );
        }
    } while( next_permutation( all(X) ) );
    output << bestArea << endl;
    for( set<pii>::iterator it = result.begin(); it != result.end(); ++it )
        output << it->first << " " << it->second << endl;
 	return 0;
}