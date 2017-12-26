/*
ID: deathkn2
PROG: transform
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
typedef vector<string> vs;
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
vs rotate( const vs& A )
{
    vs result(A);
    int n = A.size();
    fora2(i, j, A)
        result[j][n - i - 1] = A[i][j];
    return result;
}
vs reflect( const vs& A )
{
    vs result(A);
    int n = A.size();
    fora2(i, j, A)
       result[i][n - j - 1] = A[i][j];
    return result;
}
int main()
{
	ifstream input( "transform.in" );
	ofstream output( "transform.out" );
    int n; input >> n;
    vs A(n), B(n);
    fora(i, A)
        input >> A[i];
    fora(i, B)
        input >> B[i];
    if ( rotate( A ) == B )
    {
        output << 1 << endl;
        return 0;
    }
    if ( rotate( rotate( A ) ) == B )
    {
        output << 2 << endl;
        return 0;
    }
    if ( rotate( rotate( rotate( A ) ) ) == B )
    {
        output << 3 << endl;
        return 0;
    }
    if ( reflect( A ) == B )
    {
        output << 4 << endl;
        return 0;
    }
    if ( rotate( reflect( A ) ) == B || rotate( rotate( reflect( A ) ) ) == B || rotate( rotate( rotate( reflect( A ) ) ) ) == B)
    {
        output << 5 << endl;
        return 0;
    }
    if ( A == B )
    {
        output << 6 << endl;
        return 0;
    }
    output << 7 << endl;
	return 0;
}