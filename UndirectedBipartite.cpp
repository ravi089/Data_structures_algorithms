// Graph algorithms.
// Check if the given graph is bipartite.

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
vector<int> color;

bool bfs( vector<string> s )
{
	N = s.size();
	visited.resize(N);
	color.resize(N);
	g1.resize(N);
	bool bipartite = true;
	for ( int i = 0; i < N; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			if ( s[i][j] == '1' ) 
				g1[i].push_back(j);

	queue<int> q;
	q.push(0);
	color[0] = 1;
	while ( !q.empty() ) {
		int i = q.front();
		q.pop();
		if ( visited[i] ) continue;
		visited[i] = true;
		for ( vector<int>::iterator it = g1[i].begin(); it != g1[i].end(); ++it ) {
			if ( color[*it] == color[i] ) {
				bipartite = false;
				break;
			}
			(color[i] == 1) ? color[*it] = 2 : color[*it] = 1;
			q.push(*it);
		}
		if ( !bipartite )  break;
	}
	return bipartite;
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
	/*
	string str[] = {"01100000",
					"10011000",
					"10000011",
					"01000100",
					"01000101",
					"00011000",
					"00100000",
					"00101000"};
	*/
	vector<string> s(str, str+sizeof(str)/sizeof(str[0]));

	if ( bfs(s) )  cout << "Given graph is bipartite." << endl;
	else  cout << "Given graph is not bipartite." << endl;

	system("pause");
    return 0;
}
