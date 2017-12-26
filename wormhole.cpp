/*
ID: deathkn2
PROG: wormhole
LANG: C++
*/

#ifdef BOOST
#include <boost/chrono/include.hpp>
#endif

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
#include <utility>
using namespace std;

int main()
{
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t0 = boost::chrono::high_resolution_clock::now();
#endif
	ifstream input( "wormhole.in" );
	ofstream output( "wormhole.out" );
    int N;
    input >> N;
    vector<int> X( N );
    vector<int> Y( N );
    for ( int i = 0; i < N; ++i )
        input >> X[i] >> Y[i];
    input.close();
    int result = 0;
    vector<int> Next( N, -1 );
    for (int i = 0; i < N; ++i)
    {
        int x = X[i];
        int nx = 1 << 30;
        for (int j = 0; j < N; ++j)
            if (Y[i] == Y[j] && x < X[j] && X[j] < nx)
            {
                nx = X[j];
                Next[i] = j;
            }
    }
    queue<int> Q; queue<vector<int> > V;
    Q.push( 0 ); V.push( vector<int>( N, -1 ) );
    while ( !Q.empty() )
    {
        int length = Q.front(); Q.pop();
        vector<int> pairs = V.front(); V.pop();
        int points = 0, a = 0;
        for ( int k = 0; k < N; ++k )
            if ( pairs[k] < 0 )
            {
                if ( points == 0 )
                {
                    a = k;
                    ++points;
                    continue;
                }
                vector<int> current( pairs );
                current[a] = k;
                current[k] = a;
                if ( length + 2 == N )
                {
                    int is_cycle = 0;
                    vector<int> visited( N, -1 );                    
                    for ( int start = 0; start < N; ++start )
                        if (visited[start] < 0)
                        {
                            int next = start;
                            while (true)
                            {
                                if (visited[next] >= 0)                                
                                {
                                    if (visited[next] == start)
                                        is_cycle = 1;
                                    break;
                                }
                                else
                                {
                                    visited[next] = start;
                                    if (Next[next] < 0)
                                        break;
                                    next = current[Next[next]];
                                }
                            }
                            if (is_cycle)
                                break;
                        }
                    result += is_cycle;
                }
                else
                {
                    V.push( current );
                    Q.push( length + 2 );
                }
            }
    }
    output << result << endl;
    output.close();
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t1 = boost::chrono::high_resolution_clock::now();
    cout << "That took " << boost::chrono::round<boost::chrono::milliseconds>( t1 - t0 ) << '\n';
#endif
    return 0;
}