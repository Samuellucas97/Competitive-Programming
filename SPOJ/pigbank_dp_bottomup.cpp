#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int numberOfTests;
	cin >> numberOfTests;
	
	int INVALID = INT_MAX;
	int res = INVALID;

	int E, F;
	int E_F_diference;	
	
	int N;
	int P, W;
		
	vector<int> w;
	vector<int> v;	
	
	for(int t=1; t <= numberOfTests; ++t) {
		cin >> E >> F;
		E_F_diference = F-E;
	
		cin >> N;

		w.clear();
		v.clear();

		for (int n=1; n <= N; ++n) {
			cin >> P >> W;
			v.push_back(P);
			w.push_back(W);
		}	
		
		vector<vector<int>> dp(E_F_diference+1, vector<int>(N, INVALID));
		vector<int> dp_aux(E_F_diference+1, INVALID);

		for (int i=0; i < N; ++i) 
			dp[0][i] = 0;
		
		dp_aux[0] = 0;   // Menor valor para W=0
		
		for (int i=1; i <= E_F_diference; ++i) {
			for (int j=0; j < N; ++j) {
				
					if (i >= w[j] && dp_aux[i-w[j]] != INVALID) {
						dp[i][j] = min( dp[i][j],  v[j] + dp_aux[i-w[j]] ); 		
						dp_aux[i] = min(dp_aux[i], dp[i][j]);		
					}
				
			} // O (E_F_diference * N * N);
		}
	
		res = INVALID;
		for (int j=0; j < N; ++j) {
			res = min(res, dp[E_F_diference][j]);
		}
	
	
		if (res != INVALID)
			cout << "The minimum amount of money in the piggy-bank is " <<  res << ".\n";
		else
			cout << "This is impossible.\n";
	}
		
	return 0;
}