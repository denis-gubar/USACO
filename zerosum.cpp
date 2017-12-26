/*
ID: deathkn2
PROG: zerosum
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
#define all(v) (v).begin(), (v).end()
int main()
{
	int N;
	ifstream input( "zerosum.in" );
	input >> N;
	ofstream output( "zerosum.out" );
	vi X(N - 1);
	int k = 1;
	fora(i, X)
		k *= 3;
	for( int x = 0; x < k; ++x )
	{
		int n = x;
		vi A;
		A.push_back( 1 );
		fora(i, X)
		{
			X[i] = n % 3;
			n /= 3;
		}
		reverse( all(X) );
		fora(i, X)
		{
			switch( X[i] )
			{
			case 0:
				A.back() = A.back() * 10 + i + 2;
				break;
			case 1:
				A.push_back( i + 2 );
				break;
			case 2:
				A.push_back( i + 2 );
				break;
			default:
				break;
			}
		}
		int result = A[0];
		int j = 0;
		fora(i, X)
			switch( X[i] )
			{
			case 0:
				break;
			case 1:
				++j;
				result += A[j];
				break;
			case 2:
				++j;
				result -= A[j];
				break;
			default:
				break;
			}
		if ( result == 0 )
		{
			output << 1;
			fora(i, X)
			{
				switch( X[i] )
				{
				case 0:
					output << ' ';
					break;
				case 1:
					output << '+';
					break;
				case 2:
					output << '-';
					break;
				default:
					break;
				}
				output << i + 2;
			}
			output << endl;
		}
	}
	return 0;
}