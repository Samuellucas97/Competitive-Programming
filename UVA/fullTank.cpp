#include<bits/stdc++.h>
using namespace std;

struct MyTriple {
    int y;
    int capacity;
    int cost;
    MyTriple(int n1, int n2, int n3) : y(n1), capacity(n2), cost(n3) { }
};


bool operator < (MyTriple a,MyTriple b) {
    return a.cost > b.cost;
}
 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int INF = -1;
	
	int x, y, distance, capacity;
	int startNode, finishNode;
	
	int nNodes, mEdges;
	cin >> nNodes >> mEdges;
		
	int nPrices[nNodes];
	for (int i=0; i<nNodes; ++i) cin >> nPrices[i];
	
	vector<pair<int, int>> adjacencyList[nNodes];
 	for (int i=0; i<mEdges; ++i) {
		cin >> x >> y >> distance;	
		adjacencyList[x].push_back({y, distance});	
		adjacencyList[y].push_back({x, distance});		
	}
	

	int nQueries;
	cin >> nQueries;
	
	
	for (int k=0; k<nQueries; ++k) {
		cin >> capacity >> startNode >> finishNode;	
						
		int costs[nNodes][capacity+2];			
		
		for (int i=0;i<nNodes;++i) {
			for (int j=0;j<=capacity;++j) {
				costs[i][j] = INF;
			}
		}

		priority_queue<MyTriple> q;

		int actualNode; 
		int actualCapacity; 
		int actualCost;
		
		int finalCost = INF;
		
		q.push(MyTriple(startNode,0,0));		
		while(!q.empty()) {
			actualCost = q.top().cost;
			actualNode = q.top().y;
			actualCapacity = q.top().capacity;
			q.pop();
			
		
			/// Cheguei na cidade, destino final
			if (actualNode == finishNode) {
				finalCost = actualCost;
				break;			
			}
			
			
			/// Se esse estado já foi atingido, prossigo 
			if (costs[actualNode][actualCapacity] != INF) {
				continue;
			}
				
			costs[actualNode][actualCapacity] = actualCost;  
			
			
			// Abastecendo na 
			if (actualCapacity < capacity) 	{
				q.push(MyTriple(actualNode, actualCapacity+1, actualCost+nPrices[actualNode]));
			}
			
			
			// Cidades Vizinhas
			for (auto neighbor: adjacencyList[actualNode] ) {
				int nodeNeighbor = neighbor.first;
				int distanceNeighbor = neighbor.second;
					
				/// Tenho combustível suficiente para ir até a cidade vizinha
				
				if (actualCapacity >= distanceNeighbor) {							
					q.push(MyTriple(nodeNeighbor, actualCapacity-distanceNeighbor,actualCost ));	
				}
			}			
		}
		
    
		if (finalCost != INF) cout << finalCost << "\n";
		else cout << "impossible\n";
		
	}	
	
	return 0;
}
