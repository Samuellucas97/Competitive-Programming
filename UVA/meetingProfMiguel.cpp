#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int INF = 100000;
	
	int nEdges;
	char permission; // 'Y' ou 'M'
	char direction;  // 'B' ou 'U'
	char X, Y;
	int energyNecessary;
	char myPosition, professorPosition;
	
	set<int> nodes;
	int aux, finalEnergyNecessary;
	
	map<int, vector<char>> res;
	set<char> resPositions;
	
	int matrixAdjacencyYoung[26][26];		
	int matrixAdjacencyAdult[26][26];
	
	cin >> nEdges;		
	while (nEdges != 0) {	
		nodes.clear();
		res.clear();
		resPositions.clear();
		

		int distancesYoung[26][26];		
		int distancesAdult[26][26];
		
		
		for (int i=0; i < 26;++i) {
			for (int j=0; j < 26;++j) {
				if (i == j) {
					matrixAdjacencyYoung[i][i] = 1;
					matrixAdjacencyAdult[i][i] = 1;
				}
				
				else {
					matrixAdjacencyYoung[i][j] = 0;
					matrixAdjacencyAdult[i][j] = 0;
				}
			}
		}
		
		for (int i=0; i < 26;++i) {
			for (int j=0; j < 26;++j) {
				if (i == j) {
					distancesYoung[i][i] = 0;
					distancesAdult[i][i] = 0;
				}
				
				else {
					distancesAdult[i][j] = INF;
					distancesYoung[i][j] = INF;
				}
			}
		}
				
		for (int s=0; s<nEdges; ++s) {
			cin >> permission >> direction >> X >> Y >> energyNecessary;
		
			nodes.insert(X-'A');
			nodes.insert(Y-'A');
		
			if (permission == 'Y') {
				matrixAdjacencyYoung[X-'A'][Y-'A'] = 1;
				
				distancesYoung[X-'A'][Y-'A'] = min (distancesYoung[X-'A'][Y-'A'], 
														energyNecessary);
				
				if (direction == 'B') { 		
					matrixAdjacencyYoung[Y-'A'][X-'A'] = 1;
					distancesYoung[Y-'A'][X-'A'] = min(distancesYoung[Y-'A'][X-'A'],
														energyNecessary);
				}
			}
			else {
				matrixAdjacencyAdult[X-'A'][Y-'A'] = 1;
				
				distancesAdult[X-'A'][Y-'A'] = min (distancesAdult[X-'A'][Y-'A'], 
													energyNecessary);
				
				
				if (direction == 'B') { // Adicionando outro lado da aresta		
					matrixAdjacencyAdult[Y-'A'][X-'A'] = 1;
				
					distancesAdult[Y-'A'][X-'A'] = min (distancesAdult[Y-'A'][X-'A'], 
														energyNecessary);
				}
			}
		}		
				
		for (int k = 0; k < 26; ++k) {
			for (int i = 0; i < 26; ++i) {
				for (int j = 0; j < 26; ++j) {
					if (distancesAdult[i][k] != INF && distancesAdult[k][j] != INF)
						distancesAdult[i][j] = min(distancesAdult[i][j],
												distancesAdult[i][k]+distancesAdult[k][j]);
												
					if (distancesYoung[i][k] != INF && distancesYoung[k][j] != INF)
						distancesYoung[i][j] = min(distancesYoung[i][j],
												distancesYoung[i][k]+distancesYoung[k][j]);
				}
			}
		}
		
		cin >> myPosition >> professorPosition;
		
		if (myPosition == professorPosition) res[0].push_back(myPosition);
		
		finalEnergyNecessary = INF;
		
		for (int i=0; i < 26; ++i) {
			if ( distancesYoung[myPosition-'A'][i] != INF && distancesAdult[professorPosition-'A'][i] != INF) {
		
				aux = distancesYoung[myPosition-'A'][i] + distancesAdult[professorPosition-'A'][i];
				
				if ( finalEnergyNecessary == aux ) {
					res[finalEnergyNecessary].push_back((char)(i+65));
				}

				else if (finalEnergyNecessary > aux ) {
					res[finalEnergyNecessary].clear();
					finalEnergyNecessary = aux;
					
					res[finalEnergyNecessary].push_back((char)(i+65));
				}
				
			}
		}


		
		
		if (res.size() > 0 ) {
			finalEnergyNecessary = (*res.begin()).first;			
			cout << finalEnergyNecessary;
			
			for (auto j: res[finalEnergyNecessary]) {
				if (resPositions.find(j) == resPositions.end() ) {
					cout << " " << j;
					resPositions.insert(j);
				}
			}
			cout << "\n";
		}
		else {
			cout << "You will never meet.\n";
		}
			
		cin >> nEdges;
	}
	
	return 0;
}
