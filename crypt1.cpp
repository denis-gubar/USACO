/*
ID: deathkn2
PROG: crypt1
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
#define fora(i,v) for(int i = 0; i < (v).size(); i++)
#define all(v) (v).begin(), (v).end()
bool check( int x, int MAX, vi& A )
{
	if ( x > MAX ) return false;
	while( x )
		if ( find( all(A), x % 10 ) == A.end() ) return false;
		else x /= 10;
	return true;
}
int main()
{
	ifstream input( "crypt1.in" );
	int n; input >> n; vi A(n);
	copy( istream_iterator<int>( input ), istream_iterator<int>(), A.begin() );
	int result = 0;
	fora(a, A)
		fora(b, A)
			fora(c, A)
			{
				int x = A[a] * 100 + A[b] * 10 + A[c];
				vi B;
				fora(d, A)
					if ( check( x * A[d], 999, A ) )
						B.push_back( x * A[d] );
				fora(i, B)
				{
					int y = B[i] * 10;
					fora(j, B)
						if ( check( y + B[j], 9999, A ) )
							result++;
				}
			}
	ofstream output( "crypt1.out" );
	output << result << endl;
	return 0;
}