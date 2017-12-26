/*
ID: deathkn2
PROG: checker
*/

#include <fstream>
#include <iostream>
#include <memory.h>

using namespace std;

int x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int y[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int f[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int n, n_1, n1, result = 0, i = -1;
ofstream output( "checker.out" );

void calc()
{
	++i;
	for( int j = 1; j <= n; ++j )
	{
		if ( !f[j] )
		{
			bool flag = true;
			for( int k = i - 1; k >= 0; --k )
				if ( i - k == abs(x[k] - j) )
				{
					flag = false;
					break;
				}
			if ( flag )
			{
				x[i] = j;  f[j] = 1;
				if ( i == n_1 )
				{
					if ( result < 3 )
					{
						for( int j = 0; j < n_1; ++j )
							output << x[j] << ' ';
						output << x[n_1] << endl;
					}
					if ( x[0] * 2 >= n && n > 6 )
					{
						if ( y[0] )
						{
							for( int k = 1; k < n; ++k )
								if ( x[k] + y[k] != n1 )
								{
									flag = false; break;
								}
							if ( flag )
							{
								output << result * 2 << endl;
								exit(0);
							}
						}
						::memcpy( y, x, n * sizeof(int) );
					}
					++result;
				}
				else calc();
				f[j] = 0;
			}
		}
	}
	--i;
}
int main()
{
	ifstream input( "checker.in" );
	input >> n; n_1 = n - 1; n1 = n + 1;
	calc(); output << result << endl;
	return 0;
}