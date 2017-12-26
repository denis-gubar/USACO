/*
ID: deathkn2
PROG: maze1
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main()
{
	ifstream input( "maze1.in" );
	int w, h; input >> w >> h;
	vs M(2 * h + 1);
	queue<int> q;
	vvi A(h, vi(w, w * h));
	string temp; getline( input, temp );
	for( int i = 0; i < 2 * h + 1; ++i )
		getline( input, M[i] );
	for( int i = 0; i < h; ++i )
	{
		if ( M[2 * i + 1][0] == ' ' )
		{
			q.push( i ); q.push( 0 ); A[i][0] = 1;
			M[2 * i + 1][0] = '|';
		}
		if ( M[2 * i + 1][2 * w] == ' ' )
		{
			q.push( i ); q.push( w - 1 ); A[i][w - 1] = 1;
			M[2 * i + 1][2 * w] = '|';
		}
	}
	for( int j = 0; j < w; ++j )
	{
		if ( M[0][2 * j + 1] == ' ' )
		{
			q.push( 0 ); q.push( j ); A[0][j] = 1;
			M[0][2 * j + 1] = '-';
		}
		if ( M[2 * h][2 * j + 1] == ' ' )
		{
			q.push( h - 1 ); q.push( j ); A[h - 1][j] = 1;
			M[2 * h][2 * j + 1] = '-';
		}
	}
	while( !q.empty() )
	{
		int x = q.front(); q.pop();
		int y = q.front(); q.pop();
		for( int i = 0; i < 4; ++i )
		{
			int nx = x + dx[i], ny = y + dy[i];
			if ( nx >= 0 && nx < h && ny >= 0 && ny < w && M[2 * x + 1 + dx[i]][2 * y + 1 + dy[i]] == ' ' && A[nx][ny] > A[x][y] + 1 )
			{
				A[nx][ny] = A[x][y] + 1; q.push( nx ); q.push( ny );
			}
		}
	}
	int result = 0;
	for( int i = 0; i < h; ++i )
		result = max( result, *max_element( all(A[i]) ) );
	ofstream output( "maze1.out" );	
	output << result << endl;
	return 0;
}