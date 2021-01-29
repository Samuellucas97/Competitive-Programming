#include<bits/stdc++.h>
using namespace std;

void imprime(vector<int> i, int d) {
	cerr << "[ ";
	for (int a: i) {
		cerr << a << " "; 
	}
	cerr << "] (" << d << ")\n";
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int nTests;
	cin >> nTests;
	
	int x;
	vector<int> targetConfig, initialConfig;	
	vector<int> auxConfig;

	int nBlocked;
	vector<int> blockedConfig;
	
	// BFS
	map<vector<int>, bool> visitados; 
	map<vector<int>, int> distancias;
	
	for (int k=0; k<nTests; ++k) {
		
		/// RESETANDO
		visitados.clear();
		distancias.clear();
			
		// LENDO CONFIG. INICIAL	
		initialConfig.clear();
		for (int i=3;i>=0;--i) {
			cin >> x;
			initialConfig.push_back(x);
		}
		
		// READING TARGET CONFIGURATION
		targetConfig.clear();
		for (int i=3;i>=0;--i) {
			cin >> x;
			targetConfig.push_back(x);
		}
		
		// GETTING BLOCKED CONFIGURATIONS
		cin >> nBlocked;
		for (int j=1;j<=nBlocked; ++j) {
			blockedConfig.clear();
			for (int i=3;i>=0;--i) {
				cin >> x;
				blockedConfig.push_back(x) ;
			}
						
			visitados[blockedConfig] = true;
			distancias[blockedConfig] = -1;
		}
		
		for (auto i: visitados) {
			imprime(i.first, distancias[i.first]);
		}
		
		
		if (visitados.find(targetConfig) != visitados.end() ) {
			cout << "-1\n";
		}	
		else if (initialConfig == targetConfig){
			cout << "0\n";
		}	
		else {	
			// CRIAR FILA 
			queue<vector<int>> q;
			
			cerr << "\n\n";
			imprime(initialConfig, distancias[initialConfig]);
			
			// MARCAR COMO VISITADO A CONFIGURACAO INICIAL
			visitados[initialConfig] = true;
			
			// COLOCAR DISTANCIA 0 DA CONFIG. INICIAL
			distancias[initialConfig] = 0;
			
			cerr << "\n\n";
			imprime(initialConfig, distancias[initialConfig]);
			
			// CRIAR ARRAY COM OS DIGITOS DA CONF INICIAL
			auxConfig = initialConfig;
			
			// ADICIONAR NA FILA OS ESTADOS ADJACENTES (+1 E -1 PARA TODOS OS QUATRO DIGITOS)
			int o;
			
			for (int i=0; i<=3; ++i) {
				o = auxConfig[i];
				auxConfig[i] = (auxConfig[i] + 1) % 10;
				
				if (visitados.find(auxConfig) == visitados.end() ) {
					// COLOCAR COMO DISTANCIA 1 ESSES ESTADOS ADJACENTES
					distancias[auxConfig] = 1;	
				
					// MARCAR COMO NÃO VISITADO ESSES ESTADOS ADJACENTES
					visitados[auxConfig] = false;	
				
					q.push(auxConfig);
				}
			
				auxConfig[i] = o;				
			}
		
			/**for (auto i: visitados) {
				cerr << i.first[0] << " | Visitado: " << i.second << "\n";
			}*/		

			int l;	
			for (int i=0; i<=3; ++i) {
				o = auxConfig[i];
				
				l = auxConfig[i] - 1;
				if (l >= 0)
					auxConfig[i] = l;
				else 
					auxConfig[i] = 9;
				
				if (visitados.find(auxConfig) == visitados.end() ) {
				
					// COLOCAR COMO DISTANCIA 1 ESSES ESTADOS ADJACENTES
					distancias[auxConfig] = 1;	
				
					// MARCAR COMO NÃO VISITADO ESSES ESTADOS ADJACENTES
					visitados[auxConfig] = false;	
			
					q.push(auxConfig);
				}
			
				auxConfig[i] = o;				
			}
			
			
			/**for (auto i: visitados) {
				cerr << i.first[0] << " | Visitado2: " << i.second << "\n";
			}*/		
			
			// LOOP ENQUANTO A FILA Q NÃO É VAZIA
			//
			
			while(!q.empty()) {
				
				// COLOCO NO NÓ **KK** O CARA DA FRENTE DA FILA
				auxConfig = q.front(); 
			
				//cout << "Actual:" << aux << " [" << h << "]\n";
				//++h;
								 
				// REMOVO DA LISTA O PRIMEIRO ELEMENTO DA FILA
				q.pop();
				
				// SE O NO **KK** JÁ FOI VISITADO CONTINUO
				if (visitados[auxConfig] == true)  { 
					//cerr << "FIM DESSA LINHA! \n";
					continue;
				}
				// SE NAO, MARCO O NOH **KK** COMO VISITADO
				visitados[auxConfig] = true;
				
				// SE O NÓ X POSSUI VALOR IGUAL A CONFIGURAÇÃO ALVO EU PARO
				if (auxConfig == targetConfig) {	
					//cerr << "ENCONTROU! \n";
					break;				
				}
				
				// ADICIONO TODOS O ESTADOS ADJACENTES 
						
				initialConfig = auxConfig;
				
				for (int i=0; i<=3; ++i) {
					o = initialConfig[i];
					initialConfig[i] = (initialConfig[i] + 1) % 10;
									
					
					if ( visitados.find(initialConfig) == visitados.end() ) {
						visitados[initialConfig] = false;
						distancias[initialConfig] = -1;
					}
					
					if ( visitados[initialConfig] == false) {
						// COLOCAR COMO DISTANCIA DE AUX+1 ESSES ESTADOS ADJACENTES
						distancias[initialConfig] = distancias[auxConfig] + 1;	
					
						// MARCAR COMO NÃO VISITADO ESSES ESTADOS ADJACENTES
						//visitados[initialConfig] = false;	
					
						q.push(initialConfig);
					}
					initialConfig[i] = o;				
				}
				
				initialConfig = auxConfig;
				
				for (int i=0; i<=3; ++i) {
					o = initialConfig[i];
					
					l = initialConfig[i] - 1;
					
					if (l >= 0)
						initialConfig[i] = l;
					else 
						initialConfig[i] = 9;
					
					
					if ( visitados.find(initialConfig) == visitados.end() ) {
						visitados[initialConfig] = false;
						distancias[initialConfig] = -1;
					}
					
					if ( visitados[initialConfig] == false) {						
						// COLOCAR COMO DISTANCIA DE AUX+1 ESSES ESTADOS ADJACENTES
						distancias[initialConfig] = distancias[auxConfig] + 1;	
					
						// MARCAR COMO NÃO VISITADO ESSES ESTADOS ADJACENTES
						//visitados[initialConfig] = false;	
				
						q.push(initialConfig);
					}	
					initialConfig[i] = o;				
				}
	
					
			}
			// IMPRIMO A DISTANCIA
			if (visitados[targetConfig] == true)
				cout << distancias[targetConfig] << "\n";
			else 
				cout << "-1\n";
			
			
			
			/**
			for (auto m: visitados) {
				if ( m.second == true)
					cout << m.first << " [distancia: " << distancias[m.first] <<  "] [visitado: " << m.second << "]\n";
			}
			for (auto m: distancias) {
				cout << m.first << " | " << m.second << "\n";
			}*/
			
		}
	
	}
	
	return 0;
}
