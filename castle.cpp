/*
ID: deathkn2
PROG: castle
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	ifstream input( "castle.in" );
	int m, n; input >> m >> n;
	vvi M(n, vi(m)), A(n, vi(m, -1)); vi rooms; rooms.reserve( m * n );
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < m; ++j )
			input >> M[i][j];
	int currentRoom = -1;
	for( int i = 0; i < n; ++i )
		for( int j = 0; j < m; ++j )
			if ( A[i][j] < 0 )
			{
				A[i][j] = ++currentRoom; rooms.push_back( 1 );
				queue<int> q; q.push( i ); q.push( j );
				while( !q.empty() )
				{
					int x = q.front(); q.pop();
					int y = q.front(); q.pop();
					if ( !(M[x][y] & 1) && A[x][y - 1] < 0 )
					{
						A[x][y - 1] = currentRoom; ++rooms.back();
						q.push( x ); q.push( y - 1 );
					}						
					if ( !(M[x][y] & 2) && A[x - 1][y] < 0 )
					{
						A[x - 1][y] = currentRoom; ++rooms.back();
						q.push( x - 1 ); q.push( y );
					}						
					if ( !(M[x][y] & 4) && A[x][y + 1] < 0 )
					{
						A[x][y + 1] = currentRoom; ++rooms.back();
						q.push( x ); q.push( y + 1 );
					}						
					if ( !(M[x][y] & 8) && A[x + 1][y] < 0 )
					{
						A[x + 1][y] = currentRoom; ++rooms.back();
						q.push( x + 1 ); q.push( y );
					}						
				}
			}
	int X, Y, best = 0;
	char direction;
	for( int j = 0; j < m; ++j )
		for( int i = n - 1; i >= 0; --i )
		{
			if ( i && (M[i][j] & 2) )
			{
				int room1 = A[i][j];
				int room2 = A[i - 1][j];
				if ( room1 != room2 && best < rooms[room1] + rooms[room2] )
				{
					best = rooms[room1] + rooms[room2];
					X = i; Y = j; direction = 'N';
				}
			}
			if ( j < m - 1 && (M[i][j] & 4) )
			{
				int room1 = A[i][j];
				int room2 = A[i][j + 1];
				if ( room1 != room2 && best < rooms[room1] + rooms[room2] )
				{
					best = rooms[room1] + rooms[room2];
					X = i; Y = j; direction = 'E';
				}
			}
		}
	ofstream output( "castle.out" );
	output << rooms.size() << endl;
	output << *max_element( all(rooms) ) << endl;
	output << best << endl;
	output << X + 1 << ' ' << Y + 1 << ' ' << direction << endl;
	return 0;
}