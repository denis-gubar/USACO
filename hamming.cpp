/*
ID: deathkn2
PROG: hamming
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
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
int onesCount( int x )
{
    int result = 0;
    while( x )
    {
        ++result; x &= x - 1;
    }
    return result;
}
int main()
{
	ifstream input( "hamming.in" );
	ofstream output( "hamming.out" );
    int N, B, D;
    input >> N >> B >> D;
    vi result(1);
    for( int i = 1; i < (1 << B) && result.size() < N; ++i )
    {
        int flag = true;
        fora(j, result)
            if ( onesCount( result[j] ^ i ) < D )
            {
                flag = false; break;
            }
        if ( flag )
            result.push_back( i );
    }
    fora(j, result)
    {
        if ( j )
            if ( j % 10 == 0  )
                output << endl;
            else
                output << " ";
        output << result[j];
    }
    output << endl;
	return 0;
}