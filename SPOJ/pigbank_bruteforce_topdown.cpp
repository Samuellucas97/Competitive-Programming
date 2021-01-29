#include<bits/stdc++.h>
using namespace std;

int INVALID = INT_MAX;
int NAO_COMPUTADO = -2;
vector<int> w;
vector<int> v;

int solve(int W) {
	if (W < 0)
		return INVALID;
		
	if (W == 0)
		return  0;
	
	int res = INT_MAX;
	
	for (unsigned int i=0; i<w.size(); ++i) {
		if (W >= w[i]) {
			int w_ant = solve(W-w[i]);
			if (w_ant != INVALID) {
				res = min(res, v[i] + solve(W-w[i]));	
			}
		}
	}
	
	return res;
		
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int numberOfTests;
	cin >> numberOfTests;

	int E, F;
	int E_F_diference;
	
	int N;
	int P, W;
	
	int res = INVALID;
	for(int t=1; t <= numberOfTests; ++t) {
			v.clear();
			w.clear();
	
			cin >> E >> F;
			E_F_diference = F-E;
		
			cin >> N;
			for (int n=1; n <= N; ++n) {
				cin >> P >> W;
			
				v.push_back(P);
				w.push_back(W);
			}
			
			res = solve(E_F_diference);
			
			if (res != INVALID)
				cout << "The minimum amount of money in the piggy-bank is " <<  res << ".\n";
			else
				cout << "This is impossible.\n";
	}
	
	return 0;
}