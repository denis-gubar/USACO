/*
ID: deathkn2
PROG: stamps
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
	int K, N;
	ifstream input( "stamps.in" );
	input >> K >> N;
	vi A(N);
	fora(i, A)
		input >> A[i];
	sort( all(A), greater<int>() );
	A.erase( unique( all(A) ), A.end() );
	vector<int> F(2000002, K + 1);
	F[0] = 0;
	int result = 0;
	for( ; result < F.size(); ++result )
	{
		bool flag = false;
		fora(i, A)
			if ( A[i] <= result + 1 && F[result + 1 - A[i]] < K )
			{
				F[result + 1] = min<int>( F[result + 1], F[result + 1 - A[i]] + 1 );
				flag = true;
			}
		if ( !flag )
			break;
	}
	ofstream output( "stamps.out" );
	output << result << endl;
	return 0;
}