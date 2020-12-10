#include<bits/stdc++.h>
using namespace std;

vector<int>	adjList[2001];	

int res = 1;
void dfs(int actualNode, int maxHeight) {
	res = max(res, maxHeight);
		
	for (int neighbor : adjList[actualNode]) {
		dfs(neighbor, maxHeight + 1 );
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int nNodes;
	cin >> nNodes;

	int aux;
	for (int i=1; i<=nNodes; ++i) {
		cin >> aux;
		if (aux == -1) adjList[0].push_back(i);
		else adjList[aux].push_back(i);
	}
	
	dfs(0, 0);
	cout << res << "\n";

	return 0;
}
