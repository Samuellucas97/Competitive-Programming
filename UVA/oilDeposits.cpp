#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;
	char x;
	
	map<pair<int, int>, int> petroleo;
	map<pair<int, int>, int> visitados;	
	
	set<pair<int, int>> nao_visitados;	
		
	int res;
	while ( (cin >> m >> n) && m != 0 ) { 
		
		pair<int,int> k = {-1, -1};
		
		petroleo.clear();
		visitados.clear();
		nao_visitados.clear();
		
		for (int i=0;i<m;++i) {
			for (int j=0; j<n; ++j) {
				cin >> x;
				if (x == '*') {
					petroleo[{i,j}] = 0;
					visitados[{i,j}] = true;
				} else {
					petroleo[{i,j}] = 1;
					visitados[{i,j}] = false;
					
					nao_visitados.insert({i,j});
				}
			}
		}
		
		res = 0;		
		
		while(!nao_visitados.empty()) {
			++res;
			
			k = (*nao_visitados.begin());
			
			nao_visitados.erase(k);
			visitados[k]= true;
			
			queue<pair<int, int>> q;
			
			if ( (k.first-1 >= 0) && ( visitados[{(k.first-1), k.second}] == false ) )   {
				q.push({k.first-1, k.second});
			}
			
			if ( (k.first-1 >= 0 && k.second-1 >=0) && ( visitados[{(k.first-1), (k.second-1)}] == false ) ) {
				q.push({k.first-1, k.second-1});
			}
				
			if ( (k.second-1 >= 0) && ( visitados[{k.first, (k.second-1)}] == false ) ) {
				q.push({k.first, k.second-1});
			}
			if ( (k.first+1 < m && k.second-1 >= 0) && ( visitados[{(k.first+1), (k.second-1)}] == false ) ) {
				q.push({k.first+1, k.second-1});
				
			}	
			if ( (k.first+1 < m ) && ( visitados[{(k.first+1), k.second}] == false ) ) {
				q.push({k.first+1, k.second});
				
			}
			if ( (k.first+1 < m && k.second+1 < n) && ( visitados[{(k.first+1), (k.second+1)}] == false ) ) {
				q.push({k.first+1, k.second+1});
				
			}
			if ( (k.second+1 < n) && ( visitados[{k.first, k.second+1}] == false ) ) {
				q.push({k.first, k.second+1});
			
			}
			if ( (k.first-1 >= 0 && k.second+1 <n) && ( visitados[{k.first-1, k.second+1}] == false ) ) {
				q.push({k.first-1, k.second+1});
				
			}
			
			
			while (!q.empty()) {
				k = q.front(); q.pop();
				
				if (visitados[k] == true) continue;
				
				visitados[k] = true;
				nao_visitados.erase(k);
								
							
				if ( (k.first-1 >= 0) && ( visitados[{k.first-1, k.second}] == false ) )   
					q.push({k.first-1, k.second});			
								
				if ( (k.first-1 >= 0 && k.second-1 >=0) && ( visitados[{k.first-1, k.second-1}] == false ) ) 
					q.push({k.first-1, k.second-1});
					
				if ( (k.second-1 >= 0) && ( visitados[{k.first, k.second-1}] == false ) )
					q.push({k.first, k.second-1});
								
				if ( (k.first+1 < m && k.second-1 >= 0) && ( visitados[{k.first+1, k.second-1}] == false ) )
					q.push({k.first+1, k.second-1});
					
				if ( (k.first+1 < m ) && ( visitados[{k.first+1, k.second}] == false ) )
					q.push({k.first+1, k.second});
				
				if ( (k.first+1 < m && k.second+1 < n) && ( visitados[{k.first+1, k.second+1}] == false ) )
					q.push({k.first+1, k.second+1});
				
				if ( (k.second+1 < n) && ( visitados[{k.first, k.second+1}] == false ) )
					q.push({k.first, k.second+1});

				if ( (k.first-1 >= 0 && k.second+1 <n) && ( visitados[{k.first-1, k.second+1}] == false ) )
					q.push({k.first-1, k.second+1});
			}
			
			
		}
		
		cout << res << "\n";
	
	}
	
	return 0;
}
