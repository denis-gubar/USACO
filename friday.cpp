/*
ID: deathkn2
PROG: friday
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
int main()
{
	ifstream input( "friday.in" );
	ofstream output( "friday.out" );
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vi result(7);
    int n, day = 6;
    input >> n;
    for(int year = 1900; year < 1900 + n; ++year )
    {
        months[1] = ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ) ? 29 : 28);
        for( int m = 0; m < 12; ++m )
        {
            ++result[day];
            day = (day + months[m]) % 7;
        }
    }
    for( int i = 6; i < 12; ++i )
        output << result[i % 7] << " ";
    output << result[5] << endl;
	return 0;
}