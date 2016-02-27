// Graph algorithms.
// Depth first search on an undirected
// graph.

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
vector<vector<int> > g1; 
vector<bool> visited; 
vector<int> parent;

void dfs( int i )
{
	if ( !visited[i] ) {
		visited[i] = true;
		for ( vector<int>::iterator it= g1[i].begin(); it != g1[i].end(); ++it ) {
			if ( parent[*it] == INT_MIN )
				parent[*it] = i;
			dfs(*it);
		}
	}
}

void dfsUtil( vector<string> s )
{
	N = s.size();
	visited.resize(N);
	parent.resize(N);
	parent[0] = -1;
	for ( int i = 1; i < N; i++ )
		parent[i] = INT_MIN;
	g1.resize(N);
	for ( int i = 0; i < N; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			if ( s[i][j] == '1' ) 
				g1[i].push_back(j);

	for ( int i = 0; i < N; i++ )
		dfs(i);

	for ( int i = 0; i < N; i++ )
		cout << "Parent of " << i << " is : " << parent[i] << endl;
}

int main() 
{
	string str[] = {"01100000",
					"10011000",
					"10000011",
					"01000100",
					"01000100",
					"00011000",
					"00100000",
					"00100000"};

	vector<string> s(str, str+sizeof(str)/sizeof(str[0]));

	dfsUtil(s);

	system("pause");
    return 0;
}
