#include<bits/stdc++.h>
#include <vector>
using namespace std;

int main() {

    int s, n;
    cin >> s >> n;

    vector<int> pesos(n, 0);
    vector<int> valores(n, 0);

    vector<vector<int>> matrixResultados(n+1, vector<int>(s+1, 0));

    for (int k=0; k < n; ++k) 
        cin >> pesos[k] >> valores[k];

    for (int i=1; i <= n; ++i) {
        for (int j=1; j <= s; ++j) {

            matrixResultados[i][j] = matrixResultados[i-1][j];

            if ( j >= pesos[i-1]) {
                int resultadoComAtual =  valores[i-1] + matrixResultados[i-1][j-pesos[i-1]];

                if (resultadoComAtual > matrixResultados[i][j] ) {
                    matrixResultados[i][j] = resultadoComAtual;
                }
            }

        }
    }

    
    cout << matrixResultados[n][s] << "\n";
    return 0;
}