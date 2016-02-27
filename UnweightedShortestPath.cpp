// Graph algorithms.
// Breadth first search on an undirected
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

void bfs( vector<string> s )
{
	N = s.size();
	visited.resize(N);
	parent.resize(N);
	g1.resize(N);
	for ( int i = 0; i < N; i++ )
		parent[i] = INT_MIN;
	for ( int i = 0; i < N; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			if ( s[i][j] == '1' ) 
				g1[i].push_back(j);

	queue<int> q;
	q.push(0);
	parent[0] = -1;
	while ( !q.empty() ) {
		int i = q.front();
		q.pop();
		if ( visited[i] ) continue;
		visited[i] = true;
		for ( vector<int>::iterator it = g1[i].begin(); it != g1[i].end(); ++it ) {
			q.push(*it);
			if ( parent[*it] == INT_MIN )
				parent[*it] = i;
		}
	}
	// Shortest path between 0 and 5.
	int x = 5;
	stack<int> sk;
	while( parent[x] != -1) {
		sk.push(x);
		x = parent[x];
	}
	sk.push(0);
	while ( !sk.empty() ) {
		cout << sk.top() << " ";
		sk.pop();
	}
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

	bfs(s);

	system("pause");
    return 0;
}
