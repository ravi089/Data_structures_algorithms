// Graph algorithms.

// Color the graph using minimum number
// of colors such that no adjacent
// vertices have same color.
// Greedy paradigm.

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<vector<int> > g;

int graphColoring( vector<string> s )
{
	int N = s.size();
	g.resize(N);
	vector<int> colors;
	vector<bool> available;
	for ( int i = 0; i < N; i++ ) {
		colors.push_back(-1);
		available.push_back(true);
	}
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			if ( s[i][j] == '1' )
				g[i].push_back(j);
		}
	}
	colors[0] = 0;
	for ( int i = 1; i < N; i++ ) {
		// Make colors of all adjacent vertices 
		// as not available.
		for ( vector<int>::iterator it = g[i].begin(); it != g[i].end(); ++it ) {
			if ( colors[*it] != -1 )
				available[colors[*it]] = false;
		}
		// Get the lowest available color.
		int j;
		for ( j = 0; j < N; j++ )
			if ( available[j] )
				break;
		// Make this vertex of this color.
		colors[i] = j;

		// Reset the available vector.
		for ( j = 0; j < N; j++ )
			available[j] = true;
	}
	sort(colors.begin(), colors.end());
	colors.erase( unique( colors.begin(), colors.end() ), colors.end() );

	return colors.size();
}

int main() 
{
	string str[] = {"01100000",
					"10011000",
					"10000011",
					"01000100",
					"01000110",
					"00011000",
					"00101000",
					"00100000"};

	vector<string> s(str, str+sizeof(str)/sizeof(str[0]));

	cout << graphColoring(s) << endl;

	system("pause");
    return 0;
}
