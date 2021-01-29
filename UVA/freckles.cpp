#include<bits/stdc++.h>
using namespace std;
	
map<pair<double, double>,pair<double, double> > links;
map<pair<double, double>, int > sizes;

pair<double, double> find(pair<double, double> x) {
	while(x != links[x]) x = links[x];
	return x;
}

bool same(pair<double, double> a, pair<double, double> b) {
	return find(a) == find(b);
}

void unite(pair<double, double> a, pair<double, double> b) {
	a = find(a);
	b = find(b);
	
	if (sizes[a] < sizes[b]) swap(a, b);
	sizes[a] += sizes[b];
	links[b] = a;
}

void imprime(pair<double, double> a) {
	cerr << "(" << a.first << ", " << a.second << ") ";
}


bool sortbyDistance(const tuple<pair<double, double>, pair<double, double>, double> & a,  
               const tuple<pair<double, double>, pair<double, double>, double> & b) { 
    return (get<2>(a) < get<2>(b)); 
} 
  
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCases;
	cin >> testCases;
	
	int nNodes;
	
	double x, y;	
	set<pair<double, double>> nodes;
	vector< tuple<pair<double, double>, pair<double, double>, double>> edgeList;
	
	set< tuple<pair<double, double>, pair<double, double>, double>> finalEdgeList;
		
	pair<double, double> a, b;
	
	double res;
	for (int k=0; k < testCases; ++k) {
		// Reset
		nodes.clear();
		edgeList.clear();
		links.clear();
		sizes.clear();
		finalEdgeList.clear();
		
		cin >> nNodes;
	
		// Lendo os nós do grafo
		for (int i=0; i<nNodes; ++i) {
			cin >> x >> y;
			nodes.insert({x,y});
		}
		
		// Adicionando as arestas a lista de arestas		
		for (pair<double, double> i: nodes) {
			for (pair<double, double> j: nodes) {
				if (i != j) {
					edgeList.push_back( 
						{	i, 
							j, 
							sqrt (pow((i.first - j.first), 2) + pow((i.second - j.second), 2))
						});
				}
			}
			
		}
		
		
		/**for (auto i: edgeList) {
			cout << "(" << get<0>(i).first << ", " << get<0>(i).second << ") " << "(" << get<1>(i).first << ", " << get<1>(i).second << ") " << get<2>(i);
			cout << "\n";
		}
				
		cerr << "\n\n";*/
		
		// Ordenando lista de arestas
		sort(edgeList.begin(), edgeList.end(), sortbyDistance); 
		
		/**for (auto i: edgeList) {
			cout << "(" << get<0>(i).first << ", " << get<0>(i).second << ") " << "(" << get<1>(i).first << ", " << get<1>(i).second << ") " << get<2>(i);
			cout << "\n";
		}
				
		cerr << "\n\n";*/
		
		
		/// Kruskal algorithm
		
		for (auto i: nodes) {
			links[i] = i;
			sizes[i] = 1;
		}
		
		for (auto i: edgeList) {
			a = get<0>(i);
			b = get<1>(i);
			if ( !same(a, b) ) { 
				finalEdgeList.insert(i);
				unite(a, b);
				
			}
		}
		
		
		/**for (auto i: edgeList) {
			cout << "(" << get<0>(i).first << ", " << get<0>(i).second << ") " << "(" << get<1>(i).first << ", " << get<1>(i).second << ") " << get<2>(i);
			cout << "\n";
		}
		cerr << "\n";*/
		
		/**for (auto i: links) {
		  imprime(i.first);		
		  imprime(i.second);
		  
			cerr << "\n";
		}
				
		cerr << "\n\n";*/
		
		res = 0;
		for (auto i: finalEdgeList) {
			res += get<2>(i);
			//cout << "(" << get<0>(i).first << ", " << get<0>(i).second << ") " << "(" << get<1>(i).first << ", " << get<1>(i).second << ") " << get<2>(i);
			//cout << "\n";
		}
		//cerr << "\n";
		
		cout << fixed;
		cout << setprecision(2);
		cout << res << "\n";
		if (k!= testCases-1) cout << "\n";
		
		
	}
	return 0;
}
