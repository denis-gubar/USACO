/*
ID: deathkn2
PROG: ttwo
*/
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;
typedef vector<string> vs;
int encode( int cx, int cy, int cd, int fx, int fy, int fd )
{
	return fd + fy * 10 + fx * 100 + cd * 1000 + cy * 10000 + cx * 100000;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void move( int& x, int& y, int& d, vs& M )
{
	int nx = x + dx[d], ny = y + dy[d];
	if ( nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && M[nx][ny] == '.' )
	{
		x = nx; y = ny;
	}
	else d = (d + 1) % 4;
}
int main()
{
	ifstream input( "ttwo.in" );
	vs M(10);
	for( int i = 0; i < 10; ++i )
		input >> M[i];
	int cx, cy, cd = 0, fx, fy, fd = 0;
	for( int i = 0; i < 10; ++i )
		for( int j = 0; j < 10; ++j )
		{
			if ( M[i][j] == 'C' )
			{
				cx = i; cy = j; M[i][j] = '.';
			}
			if ( M[i][j] == 'F' )
			{
				fx = i; fy = j; M[i][j] = '.';
			}
		}
	ofstream output( "ttwo.out" );	
	set<int> cache;
	while( cx != fx || cy != fy )
	{		
		int hash = encode( cx, cy, cd, fx, fy, fd );
		if ( !cache.insert( hash ).second )
		{
			output << 0 << endl;
			return 0;
		}
		move( cx, cy, cd, M ); move( fx, fy, fd, M );		
	}
	output << cache.size() << endl;
	return 0;
}