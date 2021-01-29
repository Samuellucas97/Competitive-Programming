#include<bits/stdc++.h>
using namespace std;
int main() {
	const int mod = 1000000007;
	const int INVALID = 0;

	int	n;
	cin >> n;

	vector<int> dp_D(n + 1, INVALID);
	vector<int> dp_ABC(n + 1, INVALID);

	dp_D[1] = 0;
	dp_ABC[1] = 1;

	for (int i=2; i <= n; ++i) {	
		dp_D[i] =  3LL* dp_ABC[i-1] % mod;
		dp_ABC[i] = (2LL*dp_ABC[i-1] + dp_D[i-1]) % mod;
	}
	
	cout << dp_D[n] << "\n";
	return 0;
}