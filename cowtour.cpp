/*
ID: deathkn2
PROG: cowtour
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
#define all(x) (x).begin(), (x).end()
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define fora2(i,j,v) fora(i,v) fora(j,v[i])
template<typename T> string ToString( T x )
{
	ostringstream S; S << x; return S.str();
}
double calc( double x1, double x2, double y1, double y2 )
{
	return sqrt( (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}
int main()
{
	int N;
	ifstream input( "cowtour.in" );
	input >> N;
	vd X(N), Y(N), D(N);
	vs S(N);
	vvd M(N, vd(N));
	fora(i, X)
		input >> X[i] >> Y[i];
	fora(i, S)
		input >> S[i];
	fora2(i, j, S)
		if ( S[i][j] == '1' )
			M[i][j] = calc( X[i], X[j], Y[i], Y[j] );
	fora(k, M)
		fora(i, M)
			fora(j, M)
				if ( i != j && M[i][k] && M[k][j] && (!M[i][j] || M[i][j] > M[i][k] + M[k][j]) )
					M[i][j] = M[i][k] + M[k][j];
	fora2(i, j, M)
		if ( D[i] < M[i][j] )
			D[i] = M[i][j];
	vd NF(D);
	fora2(i, j, M)
		if ( M[i][j] && NF[i] < NF[j] )
			NF[i] = NF[j];
	double result = 1e30;
	fora2(i, j, M)
		if ( i < j && !M[i][j] )
		{
			double x = max( max( calc( X[i], X[j], Y[i], Y[j] ) + D[i] + D[j], NF[i] ), NF[j] );
			if ( result > x )
			result = x;
		}
	ofstream output( "cowtour.out" );
	output << static_cast<int>(result) << "." << ToString<int>(1000000 + (2000000 * (result - floor(result)) + 1) / 2).substr( 1 ) << endl;
	return 0;
}