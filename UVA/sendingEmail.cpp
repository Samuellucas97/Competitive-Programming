#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCases;
	cin >> testCases;
	
	long long int  INF = LLONG_MAX;
	int actualNode, valueNodeAdj;
	long long int distanceNodeAdj;
	
	int n, m, startServer, finishServer;
	
	// Adjacency List
	map<int, vector<pair<int, long long int>> > adjList;

	int x, y, latencyBetween;
	
	for (int k=1; k <= testCases; ++k) {
		adjList.clear();
		
		cin >> n >> m >> startServer >> finishServer;
		
		bool visiteds[n];
		
		
		for (int g=0; g < m; ++g) {
			cin >> x >> y >> latencyBetween;
			
			if (adjList.find(x) == adjList.end()) 
				adjList[x] = vector<pair<int, long long int>> ();
			
			adjList[x].push_back({y, latencyBetween});	
				
			if (adjList.find(y) == adjList.end()) 
				adjList[y] = vector<pair<int, long long int>>  ();
			 
			adjList[y].push_back({x, latencyBetween});
		}
		
		/**for (auto a: adjList) {
			cout << a.first << ": [ ";
			for (auto w: adjList[a.first]) {
				cout << "(" << w.first << ", " << w.second << ") ";
			}
			cout << "]\n";
		}*/
		
		priority_queue<pair<int, long long int>> q;
		//priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, greater<pair<int, long long int>> > q;
		
		
		long long int distances[n];
		for (int g=0; g < n; ++g) {
			distances[g] = INF;
			visiteds[g] = false;
		}
		
		distances[startServer] =  0;
		q.push({0, startServer}); 	
		
		while (!q.empty()) {
			actualNode = q.top().second; q.pop();
			
			/**cerr << "\n\n";
			for (int g=0; g < n; ++g) {
				cerr << g << ":" <<  distances[g] << "\n";
			}	
			cerr << "\n\n";**/
			
			if( visiteds[actualNode] == true ) continue;
			visiteds[actualNode] = true;
			
			for (auto nodeAdj: adjList[actualNode] ) {
				valueNodeAdj = nodeAdj.first;
				distanceNodeAdj = nodeAdj.second;

				if (distances[actualNode]+distanceNodeAdj < distances[valueNodeAdj] ) {
					distances[valueNodeAdj] = distances[actualNode]+distanceNodeAdj;
					q.push({-distances[valueNodeAdj], valueNodeAdj});
				}

			}
			
		}	
		/**cerr << "\n\n";
		for (int g=0; g < n; ++g) {
			cerr << g << ":" <<  distances[g] << "\n";
		}	
		cerr << "\n\n";*/
		
		if (distances[finishServer] != INF)
			cout << "Case #" << k << ": " << distances[finishServer] << "\n";
		else
			cout << "Case #" << k << ": unreachable\n";
		
	} 
	
	return 0;
}
