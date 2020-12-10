#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int nNodes;
	cin >> nNodes;
	
	vector<int> adjList[nNodes+1];
	
	int aux;
	for (int i=1; i<=nNodes; ++i) {
		cin >> aux;
		adjList[i].push_back(aux);
	}
	
	
	bool existLoveTriangle = false;
	
	int aToB, bToC, cToA;
	for (int startPoint=1; startPoint<=nNodes; ++startPoint) {
		
		aToB = adjList[startPoint][0];
		
		bToC = adjList[aToB][0];
		
		cToA = adjList[bToC][0];
		
		if ( cToA == startPoint  ) {
			existLoveTriangle = true;
			break;
		} 
	}
	
	if (existLoveTriangle) cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
