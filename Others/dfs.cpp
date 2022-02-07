#include<bits/stdc++.h>
using namespace std;

/**
1	(1,2) , (1,4)
2	(2,1) , (2,3), (2,5)
3	(3,2) , (3,5)
4	(4,1)
5	(5,2) , (5,3)
6	(6,7)
7	(7,6)
 */

vector<int> adjList[8];
bool visitedNode[8] = {false};

void dfs(int s) {
	if (visitedNode[s] == true) return;
	visitedNode[s] = true;
	cout << s <<"\n";
	for (int &i: adjList[s]) {
		dfs(i);
	}

}
 
int main() {
	
	adjList[1].push_back(2);
	adjList[1].push_back(4);
	adjList[2].push_back(1);
	adjList[2].push_back(3);
	adjList[2].push_back(5);
	adjList[3].push_back(2);
	adjList[3].push_back(5);
	adjList[4].push_back(1);
	adjList[5].push_back(2);
	adjList[5].push_back(3);	
	adjList[6].push_back(7);	
	adjList[7].push_back(6);	
			
	dfs(6); /// Caminho começando do nó 6

	return 0;
}