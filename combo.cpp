/*
ID: deathkn2
PROG: combo
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
#include <utility>
using namespace std;

struct Close : binary_function<int, int, bool>
{
    bool operator() ( int x, int y ) const
    {
        return abs( x - y ) <= 2 || abs( N + x - y ) <= 2 || abs( N + y - x ) <= 2;
    }
    Close( int N ) : N( N ) {}
    int N;
};

int main()
{
	ifstream input( "combo.in" );
	ofstream output( "combo.out" );
    int N;
    vector<int> A( 3 );
    vector<int> B( 3 );
    vector<int> X( 3 );
    input >> N;
    input >> A[0] >> A[1] >> A[2];
    input >> B[0] >> B[1] >> B[2];
    Close close(N);
    int result = 0;
    for ( X[0] = 1; X[0] <= N; ++X[0] )
        for ( X[1] = 1; X[1] <= N; ++X[1] )
            for ( X[2] = 1; X[2] <= N; ++X[2] )
                if ( equal( A.begin(), A.end(), X.begin(), close ) || equal( B.begin(), B.end(), X.begin(), close ) )
                    ++result;
    output << result << endl;
	return 0;
}