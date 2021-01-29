#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> pesos(2000, 0);
vector<int> valores(2000, 0);

int solve(int capacidadeDisponivel, int i) {
    if (capacidadeDisponivel == 0) {
        return 0;
    }    

    if (i == 0) {
        if ( capacidadeDisponivel >= pesos[0]) {    
                return valores[0];
        }
        else {
            return 0;
        }
    }

    int semColocarAtual = solve(capacidadeDisponivel, i-1);

    int colocarAtual = 0;
    if ( capacidadeDisponivel >= pesos[i] ) {
        colocarAtual = valores[i] + solve(capacidadeDisponivel-pesos[i], i-1) ;
    }

    return max(semColocarAtual, colocarAtual);
}

int main() {

    int s, n;
    cin >> s >> n;

    valores.resize(n);
    pesos.resize(n);

    for (int k=0; k < n; ++k) {
        cin >> pesos[k] >> valores[k];
    }
    
    cout << solve(s, n) << "\n";

    return 0;
}