#include<bits/stdc++.h>
using namespace std;

/** We have this directed graph :

 N = 4 [nodes]
 M = 5 [edges]
  
 { (1,2), (2,4), (2,3), (3,4), (4,1) }

*/


int main() {
	
	int nNodes = 4+1;
	
	vector<int> adj[nNodes];
	
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(1);

	for (int i=1; i < nNodes; ++i) {
		for (long unsigned int j=0; j< adj[i].size(); ++j) {
			cout << "(" << i << " -> " << adj[i][j] << ")\n";
		}
	}
	
	return 0;
}