/*
ID: deathkn2
PROG: holstein
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
	ifstream input( "holstein.in" );
	ofstream output( "holstein.out" );
    int V, G;
    input >> V;
    vi Target(V);
    fora(i, Target)
        input >> Target[i];
    input >> G;
    vvi Scoops(G, vi(V));
    fora2(i, j, Scoops)
        input >> Scoops[i][j];
    int best = G + 1;
    vi result;
    for( int i = 0; i < (1 << G); ++i )
    {
        vi A(V), K;
        for( int j = 0; j < G; ++j )
            if ( i & (1 << j) )
                K.push_back( j );
        if ( K.size() >= best )
            continue;
        fora(k, K)
            for( int j = 0; j < V; ++j )
                A[j] += Scoops[K[k]][j];
        bool flag = true;
        fora(j, A)
            if ( A[j] < Target[j] )
            {
                flag = false;
                break;
            }
        if ( flag )
        {
            best = K.size();
            result = K;
        }            
    }
    output << best;
    fora(i, result)
        output << " " << result[i] + 1;
    output << endl;
	return 0;
}