/*
ID: deathkn2
PROG: satel
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
typedef vector<vi> vvi;
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
int main()
{
	ifstream input( "satel.in" );
	int r, c; input >> r >> c;
	vs A(r); vvi F(r, vi(c, 0));
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	for( int i = 0; i < r; ++i )
		input >> A[i];
	int counter = 0, cows = 0, cattles = 0;
	fora2(i, j, F)
		if ( A[i][j] == '#' && !F[i][j] )
		{
			F[i][j] = ++counter;
			queue<int> q; q.push( i ); q.push( j );
			while( !q.empty() )
			{
				int x = q.front(); q.pop();
				int y = q.front(); q.pop();
				for( int k = 0; k < 4; ++k )
				{
					int nx = x + dx[k], ny = y + dy[k];
					if ( nx >= 0 && nx < r && ny >= 0 && ny < c && A[nx][ny] == '#' && !F[nx][ny] )
					{
						q.push( nx ); q.push( ny ); F[nx][ny] = counter;
					}
				}
			}
			int x = i, y = j;
			while( x < r && A[x][y] == '#' ) ++x;
			--x;
			while( y < c && A[x][y] == '#' ) ++y;
			--y;
			bool flag = true;
			for( int a = max(0, i - 1); a <= min(x, r); ++a )
				for( int b = max(0, j - 1); b <= min(y, c); ++b )
					if ( a < i || a > x || b < j || b > y )
						flag &= F[a][b] != counter;
					else
						flag &= F[a][b] == counter;
			if ( flag ) ++cattles; else ++cows;
		}
	ofstream output( "satel.out" );
	output << cattles << endl;
	output << cows << endl;
	return 0;
}