/*
ID: deathkn2
PROG: prefix
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
typedef vector<string> vs;
#define fora(i,v) for(size_t i = 0; i < (v).size(); ++i)
#define all(v) (v).begin(), (v).end()
template<typename Predicate> vs parse( const string& s, Predicate predicate )
{
	vs result;
	for( size_t i = 0, j = 0, n = s.size(), isWord = 0; i <= n; ++i )
		if ( isWord == (i == n || !predicate( s[i] )) )
			if ( isWord = !isWord ) j = i;
			else result.push_back( s.substr( j, i - j ) );
	return result;
}
struct split_helper: unary_function<int, bool>
{
	explicit split_helper( string delimeter ): delimeter(delimeter) {};
	bool operator() ( int c ) const
	{
		return delimeter.find( c ) == string::npos;
	}
private: string delimeter;
};
vs split( const string& s, const string& delimeter = " " )
{
	return parse( s, split_helper( delimeter ) );
}
struct Comp: binary_function<string, string, bool>
{
    bool operator() ( const string& a, const string& b ) const
    {
        return a[0] < b[0];
    }
};
int main()
{
	ifstream input( "prefix.in" );
	ofstream output( "prefix.out" );
    string s, S;
    vs L;
    while( s != "." )
    {
        vs z( split( s ) );
        L.insert( L.end(), all(z) );
        input >> s;
    }
    s = "";
    while( !input.eof() )
    {
        S += s;
        input >> s;
    }
    int N = 0;
    fora(i, L)
    {
        reverse( all(L[i]) );
        N = max(N, static_cast<int>(L[i].size()) );
    }
    ++N;
    sort( all(L) );
    reverse( all(S) );
    vi A(N);
    A[S.size() % N] = 1;
    Comp comp;
    int result = 0, hasSolution = N - 1;
    for( int k = S.size() - 1; k >= 0 && hasSolution; --k, --hasSolution )
    {
        A[k % N] = 0;
        pair<vs::iterator, vs::iterator> it_pair = equal_range( all(L), S.substr(k, 1), comp );
        for( vs::iterator it = it_pair.first; it != it_pair.second; ++it )
            if ( A[(k + it->size()) % N] && equal( all(*it), S.begin() + k ) )
            {
                A[k % N] = 1; hasSolution = N;
                result = max(result, static_cast<int>(S.size()) - k );
                break;
            }
    }
    output << result << endl;
 	return 0;
}