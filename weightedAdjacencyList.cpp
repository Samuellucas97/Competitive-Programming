#include<bits/stdc++.h>
using namespace std;

/** We have this weighted graph :

 N = 4 [nodes]
 M = 6 [edges]
  
  
 { (1, 2, 5), (2, 4, 6), (2, 3, 7), (3,4, 5), (4, 1, 2) }

	Where (x, y, W) means that we have x -> y with W weight
*/


int main() {
	
	int nNodes = 4+1;
	
	vector<pair<int, int>> adj[nNodes];
	
	adj[1].push_back(make_pair(2, 5));
	adj[2].push_back({4, 6});
	adj[2].push_back({3, 7});
	adj[3].push_back({4, 5});
	adj[4].push_back({1, 2});

	for (int i=1; i < nNodes; ++i) {
		for (long unsigned int j=0; j< adj[i].size(); ++j) {
			cout << "(" << i << " -> " << adj[i][j].first << ") with weight: " << adj[i][j].second << "\n";
		}
	}
	
	return 0;
}