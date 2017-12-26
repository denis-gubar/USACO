/*
ID: deathkn2
PROG: subset
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
typedef long long lint;
typedef vector<lint> vl;
typedef vector<vl> vvl;
#define all(v) (v).begin(), (v).end()
int main()
{
	ifstream input( "subset.in" );
	ofstream output( "subset.out" );
    int N;
    input >> N;
    lint result = 0;
    if ( N * (N + 1) % 4 == 0 )
    {
        int z = N * (N + 1) / 4;
        vvl A(z + 1, vl(N + 1));
        A[0][0] = 1;
        for( int i = 1; i <= z; ++i )
            for( int j = 1; j <= i && j <= N; ++j )
                for( int k = 0; k < j; ++k )
                    A[i][j] += A[i - j][k];
        result = accumulate( all(A[z]), 0LL ) / 2;
    }
    output << result << endl;
	return 0;
}