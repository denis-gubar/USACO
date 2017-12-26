/*
ID: deathkn2
PROG: heritage
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

string calc( const string& inorder, const string& preorder )
{
    int n = inorder.size();
    if (n <= 1)
        return inorder;
    string root = preorder.substr( 0, 1 );
    int left_length = inorder.find( root );
    return calc( inorder.substr( 0, left_length ), preorder.substr( 1, left_length ) ) + calc( inorder.substr( left_length + 1 ), preorder.substr( left_length + 1 ) ) + root;
}

int main()
{
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t0 = boost::chrono::high_resolution_clock::now();
#endif
    ifstream input( "heritage.in" );
    string inorder, preorder;
    input >> inorder >> preorder;
    input.close();
    ofstream output( "heritage.out" );
    output << calc( inorder, preorder ) << endl;
    output.close();
#ifdef BOOST
    boost::chrono::high_resolution_clock::time_point t1 = boost::chrono::high_resolution_clock::now();
    cout << "That took " << boost::chrono::round<boost::chrono::milliseconds>( t1 - t0 ) << '\n';
#endif
    return 0;
}