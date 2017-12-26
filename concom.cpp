/*
ID: deathkn2
PROG: concom
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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
int main()
{
	ifstream input( "concom.in" );
	int k, N = 101;
	input >> k;
	vvi M(N, vi(N));
	vector<set<int> > C(N, set<int>());
	queue<int> q;
	for( ; k; --k )
	{
		int i, j, p;
		input >> i >> j >> p;
		M[i][j] = p;
		if ( i != j && p > 50 )
		{
            C[i].insert( j );
			q.push( i ); q.push( j );
		}
	}
    vvi A(M);
	while( !q.empty() )
	{
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
        fora(x, M)
            if ( a != x && b != x )
			{
				A[a][x] += M[b][x];
				if ( A[a][x] > 50 && C[a].insert( x ).second )
				{
					q.push( a ); q.push( x );					
				}
			}
	}
	ofstream output( "concom.out" );
	fora(i, C)
		for( set<int>::iterator it = C[i].begin(); it != C[i].end(); ++it )
			output << i << " " << *it << endl;
	return 0;
}