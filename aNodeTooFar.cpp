#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int nCase = 1;
	
	int nEdges;
	cin >> nEdges;
	
	while (nEdges != 0) {
		//cout << nEdges << "\n";
		int x,y;
		unordered_map<int, vector<int>> adjacencyList;
		for (int i=0;i<nEdges;++i){
			cin >> x >> y;
			adjacencyList[x].push_back(y);
			
			if (x != y)
				adjacencyList[y].push_back(x);
		}

   /**
	 for (auto k : adjacencyList)  {
		cout << k.first << ": "; 
			
		for (auto m: k.second) 
			cout << m << ", "; 
		
		cout << "\n"; 
	} */
		
		int s;
		int initialNode=-1, TTL=-1;
				
		cin >> initialNode >> TTL;
		while (initialNode != 0 && TTL >= 0) {		
			queue<int> q;
			//cout << "initNode: " << initialNode << " | TTL: " << TTL << "\n";
			unordered_map<int, bool> visited;
			unordered_map<int, int> distance;
			
			for (auto k : adjacencyList)  {
				visited.insert({k.first, false});
				distance.insert({k.first, INT_MAX});
			} 
			
			/**
			cout << "Visitado: \n";
			for (auto m : visited)  {
				cout << m.first << ": " << m.second << "\n";
			} 
			
			
			cout << "Distance: \n";
			for (auto m : distance)  {
				cout << m.first << ": " << m.second << "\n";
			} */
			
			visited[initialNode] = true;
			distance[initialNode] = 0;
			q.push(initialNode);
			
			while(!q.empty()) {
				s = q.front(); q.pop();
				for(int u: adjacencyList[s]) {
					if (visited[u] == true) continue;
					visited[u] = true;
					distance[u] = distance[s] + 1;
					q.push(u);
				}
			}
			/**
			cout << "Distance: [DEPOIS]\n";
			for (auto m : distance)  {
				cout << m.first << ": " << m.second << "\n";
			} */
			
			int res=0;
			for (auto i: distance) {
				if (i.second > TTL) res += 1;
			}
			
			cout << "Case " << nCase << ": " << res << " nodes not reachable from node " << initialNode << " with TTL = " << TTL << ".\n"; 
			++nCase;
			cin >> initialNode >> TTL;
		
		}
		
		cin >> nEdges;
		
	}
	return 0;
}




	
    /**for (auto k : adjacencyList)  {
		cout << k.first << ": "; 
			
		for (auto m: k.second) 
			cout << m << ", "; 
		
		cout << "\n"; 
	} */
