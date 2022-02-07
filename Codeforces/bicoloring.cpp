#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  
	int nNodes, nEdges;
	int x, y;
	const int INCOLOR = INT_MAX;
	
	vector<int> adjList[200];
	
	while (cin >> nNodes >> nEdges) {
		for (int i=0; i <nNodes; ++i) adjList[i].clear();
		for (int i=0; i< nEdges; ++i) {
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		
		
		queue<int> q;
		bool visited[nNodes];
		int colors[nNodes];
		
		for(int i=0;i<nNodes;++i) {
			visited[i] = false;
			colors[i] = INCOLOR;
		}
		
		int startNode = 0;
		visited[startNode] = true;
		colors[startNode] = 0; 
		q.push(startNode);
		
		int s;
		bool isPossible = true;
		while( !q.empty() && isPossible ) {
			s = q.front(); q.pop();
			for(int u: adjList[s]) {
				if ( colors[s] == colors[u] && colors[u] != INCOLOR ) {
					isPossible = false;			
				}
				if ( visited[u] ) continue;
				
				visited[u] = true;
				colors[u] = (colors[s] + 1) % 2;
				q.push(u); 
			}
		}	
		
		if (isPossible)
			cout << "BICOLORABLE.\n"; 
		else
			cout << "NOT BICOLORABLE.\n"; 
	
	
	}

	cin >> x;
	
	return 0;
}
