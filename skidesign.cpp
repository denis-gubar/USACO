/*
ID: deathkn2
PROG: skidesign
LANG: C++
*/

#ifdef BOOST
#include <boost/chrono/include.hpp>
#endif

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

int main()
{
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t0 = boost::chrono::high_resolution_clock::now();
#endif
    ifstream input( "skidesign.in" );
    int N;
    input >> N;
    vector<int> Heights( N );
    for (int i = 0; i < Heights.size(); ++i)
        input >> Heights[i];
    input.close();
    ofstream output( "skidesign.out" );
    int result = 1 << 30;
    int lo = *min_element( Heights.begin(), Heights.end() );
    int hi = *max_element( Heights.begin(), Heights.end() );
    for (int x = min( lo + 17, hi ); x <= hi; ++x)
    {
        int current = 0;
        for (int i = 0; i < Heights.size(); ++i)
            if (Heights[i] + 17 < x)
                current += (x - Heights[i] - 17) * (x - Heights[i] - 17);
            else if (Heights[i] > x)
                current += (Heights[i] - x)  * (Heights[i] - x);
        if (result > current)
            result = current;
    }
    cout << result << endl;
    output << result << endl;
    output.close();
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t1 = boost::chrono::high_resolution_clock::now();
    cout << "That took " << boost::chrono::round<boost::chrono::milliseconds>( t1 - t0 ) << '\n';
#endif
    return 0;
}