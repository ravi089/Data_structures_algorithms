// Graph algorithms.
// Minimum spanning tree for undirected graph.

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
vector<vector<pair<int, int> > > g;

vector<string> tokenize( string str, char delimiter )
{
	vector<string> results;
	ostringstream ss;
	for ( int i = 0; i <= str.size(); i++ )
	{
		if ( str[i] == delimiter || i == str.size() )
		{
			results.push_back(ss.str());
			ss.str("");
		}
		else if ( !isspace(str[i]) && str[i] != '\t' )
			ss << str[i];
	}
	return results;
}

int toNum( string str )
{
	int number = 0;
	for ( int i = 0; i < str.length(); i++ )
		number = (number * 10) + (str[i] - '0');
	return number;
}

void primSpanningTree( vector<string> s )
{
	int N = s.size();
	g.resize(N);
	vector<bool> intree;
	vector<int> distance;
	for ( int i = 0; i < N; i++ ) {
		intree.push_back(false);
		distance.push_back(INT_MAX);
	}
	for ( int i = 0; i < N; i++ ) {
		vector<string> tokens = tokenize(s[i], ',');
		for ( int j = 0; j < tokens.size(); j++ ) {
			int number = toNum(tokens[j]);
			if ( number != 0 )
				g[i].push_back(make_pair<int, int>(j, number));
		}
	}
	int cVertex = 0;
	distance[cVertex] = 0;
	while ( intree[cVertex] == false ) {
		intree[cVertex] = true;
		cout << cVertex << ' ';
		vector<pair<int, int> >::iterator it;
		for ( it = g[cVertex].begin(); it != g[cVertex].end(); ++it ) {
			int weight = it->second;
			int nVertex = it->first;
			if ( distance[nVertex] > weight && intree[nVertex] == false )
				distance[nVertex] = weight;
		}
		cVertex = 0;
		int dist = INT_MAX;
		for ( int i = 0; i < N; i++ ) {
			if ( dist > distance[i] && intree[i] == false ) {
				cVertex = i;
				dist = distance[i];
			}
		}
	}
	cout << endl;
}

int main() 
{
	string str[] = {"0,7,0,5,0,0,0",
					"7,0,8,9,7,0,0",
					"0,8,0,0,5,0,0",
					"5,9,0,0,15,6,0",
					"0,7,5,15,0,8,9",
					"0,0,0,6,8,0,11",
					"0,0,0,0,9,11,0"};

	vector<string> s(str, str+sizeof(str)/sizeof(str[0]));

	primSpanningTree(s);

	system("pause");
    return 0;
}
