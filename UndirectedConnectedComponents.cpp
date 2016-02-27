// Graph algorithms.
// Count all connected components in
// an undirected graph.

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

void dfs( int i )
{
	if ( !visited[i] ) {
		visited[i] = true;
		for ( vector<int>::iterator iter = g1[i].begin(); iter != g1[i].end(); ++iter )
			dfs(*iter);
	}
}

int connectedCnt( vector<string> s )
{
	N = s.size();
	g1.resize(N);
	visited.resize(N);
	for ( int i = 0; i < N; i++ ) 
		for ( int j = 0; j < N; j++ ) 
			if ( s[i][j] == '+' ) 
				g1[i].push_back(j);

	int conn_cnt = 0;
	for ( int i = 0; i < N; i++ ) {
		if ( !visited[i] ) {
			conn_cnt++;
			dfs(i);
		}
	}
	return conn_cnt;
}

int main() 
{
	string str[] = {"0++00000",
					"+0000000",
					"+0000+00",
					"0000+000",
					"000+0000",
					"00+00000",
					"0000000+",
					"000000+0"};

	vector<string> s(str, str+sizeof(str)/sizeof(str[0]));

	cout << connectedCnt(s) << endl;

	system("pause");
    return 0;
}
