#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int x0=-1, y0=-1;
	int x, y;
	
	map<int, vector<int>> adjList;
	map<int, bool> visitados;
	
	map<int, int> distancias;

	
	int testCase = 1;	
	int res = 0;
	int aux;
	
	int m;
	while ((cin >> x >> y) && (!(x == x0 && x==0) || !(y == y0 && y==0)) ) { 
		if (x != 0 || y!=0) {
			if (adjList.find(x) == adjList.end()) {
				adjList[x] = vector<int>();
			}
			
			if (adjList.find(y) == adjList.end()) {
				adjList[y] = vector<int>();
			}
						
			// SALVAR NA LISTA DE ADJACENCIA			
			adjList[x].push_back(y);	
			
			// ADICIONAR OS NÓS X E Y COMO NÃO VISITADOS
			if ( visitados.find(x) == visitados.end() )
				visitados[x] = false;
			
			if ( visitados.find(y) == visitados.end() )
				visitados[y] = false;			
			
		}
		else {
			
			// REALIZAR BUSCA EM LARGURA SOB CADA NÓ
			
			//cerr << "\n";
			m = 0;
			for (auto i: adjList) {
				//cerr << i.first << ": ";
				
				queue<int> q;
				
				visitados[i.first] = true;
				distancias[i.first] = 0;
				q.push(i.first);
				
				
				while(!q.empty()) {
					aux = q.front(); q.pop();
				
					//cerr << "|| " << aux << " \n| ";
					
					for (auto j: adjList[aux]) {
						//cerr << j << " ";
						
						if (visitados[j]) continue;
						visitados[j] = true;
						distancias[j] = distancias[aux] + 1;
						q.push(j);
					}
					
					
					//cerr << "\n";
				}
				
				
				//cout << i.first << " :[ ";
				for (auto l: visitados) {
					if (l.first != i.first) {
						res += distancias[l.first];
						++m;
						//cout << l.first << " ("<< distancias[l.first] << ") ";
					}
					visitados[l.first] = false;
					
				}
				
				//cout << "]\n";
				
				
				/**
				cerr << "\n";
				for (auto l: visitados) {
					cerr << "( " << l.first << " " << l.second << " ) "; 
				}
				cerr << "\n\n";*/
			}
			
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
			cout << "Case " << testCase << ": average length between pages = " << ( (double) res / m ) << " clicks\n";
			++testCase;
			res = 0;
			distancias.clear();
			adjList.clear();
			visitados.clear();
		}
		
		x0 = x;
		y0 = y;
	}
	
	return 0;
}
