/*
ID: deathkn2
PROG: ariprog
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
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define fora(i,v) for(size_t i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
int main()
{
	ifstream input( "ariprog.in" );
	ofstream output( "ariprog.out" );
    int N, M;
    input >> N >> M;
    int m = 2 * M * M;
    string A(m + 1, '0');
    vpii result;
    for( int p = 0; p <= M; ++p )
        for( int q = p; q <= M; ++q )
            A[p * p + q * q] = '1';
    for( int a = 0; a < m - N + 1; ++a )
        if ( A[a] == '1' )
            for( int b = 1; a + (N - 1) * b <= m; ++b )
            {
                bool flag = true;
                for( int n = 1; n < N; ++n )
                    if ( A[a + n * b] == '0' )
                    {
                        flag = false;
                        break;
                    }
                if ( flag )
                    result.push_back( make_pair(b, a) );
            }
    if ( result.empty() )
        output << "NONE" << endl;
    else
    {
        sort( all(result) );
        fora(i, result)
            output << result[i].second << " " << result[i].first << endl;
    }
	return 0;
}