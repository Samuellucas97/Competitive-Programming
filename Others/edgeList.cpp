#include<bits/stdc++.h>
using namespace std;

/** We have this weighted graph :

 N = 4 [nodes]
 M = 6 [edges]
  
  
 { (1, 2, 5), (2, 4, 6), (2, 3, 7), (3,4, 5), (4, 1, 2) }

	Where (x, y, W) means that we have x -> y with W weight
*/


int main() {
	
	vector<pair<int, int>> edjList;
	
	edjList.push_back({1, 2});
	edjList.push_back({2, 4});
	edjList.push_back({2, 3});
	edjList.push_back({3, 4});
	edjList.push_back({4, 1});

	for( pair<int, int> & i: edjList) {
		cout << "(" << i.first << " -> " << i.second << ")\n";
	}
	return 0;
}