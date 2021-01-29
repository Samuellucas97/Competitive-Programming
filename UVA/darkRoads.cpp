#include<bits/stdc++.h>
using namespace std;

vector<int> links;
vector<int> sizes;

int find(int x) {
	while (x != links[x]) x = links[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	
	if (sizes[a] < sizes[b]) swap(a,b);
	sizes[a] += sizes[b];
	links[b] = a;
}


bool sortbyWeight(const tuple<int, int, int> & a,  
               const tuple<int, int, int> & b) { 
    return (get<2>(a) < get<2>(b)); 
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int mNodes, nEdges;
	
	cin >> mNodes >> nEdges;
	
	int x, y, weight;
	
	int beforeTotal, afterTotal;
	int a,b;
	
	vector<tuple<int, int, int>> edgesList;
	set<tuple<int, int, int>> edgesSet;
	
	
	while (mNodes != 0 || nEdges != 0) {
		edgesList.clear();
		links.clear();
		sizes.clear();
		edgesSet.clear();
		
		beforeTotal = 0;
		for (int i=0; i < nEdges; ++i) {
			cin >> x >> y >> weight;
			edgesList.push_back({x, y, weight});
			edgesList.push_back({y, x, weight});
			beforeTotal += weight;
		}
		
		/// Kruskal  algorithm

		// Initialization
		for (int i=0; i<mNodes; ++i) { 
			links.push_back(i); 
			sizes.push_back(1);
		}

		/**for (auto i: edgesList) {
			cout << "( " << get<0>(i) << ", " << get<1>(i) << ", " << get<2>(i) << ")\n";
		}*/
		
		// Ordenando lista de arestas
		sort(edgesList.begin(), edgesList.end(), sortbyWeight); 
		
		/**cerr << "\n\n";
		for (auto i: edgesList) {
			cout << "( " << get<0>(i) << ", " << get<1>(i) << ", " << get<2>(i) << ")\n";
		}*/
		
		for (auto i: edgesList) {
		
			a = get<0>(i);
			b = get<1>(i);
		
		  	if (!same(a,b)) { 
		  		// Add in the final edge set  
		  		edgesSet.insert(i);
		  		unite(a, b);
		 	}
		 }
		 
		afterTotal = 0;
		for(auto i: edgesSet) {
			afterTotal += get<2>(i);
		}
			
		cout << (beforeTotal-afterTotal) << "\n";
	
		cin >> mNodes >> nEdges;
	}
	
	return 0;
}
