#include<bits/stdc++.h>
using namespace std;
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;
typedef long long ll;

const ll mod = 1000000007;
const int INVALID = 0;

vector<int> dp_D;
vector<int> dp_ABC;

// D == 1
//ABC == 0
int solve(int position, int size) {
	if (size == 1) {
		if (position == 1) return 0;
		else return 1;
	} 

	if ( position == 1) {
	
		if (dp_D[size] != INVALID)
			return dp_D[size];
		
		if (dp_ABC[size-1] == INVALID) {
			dp_ABC[size-1] = solve(0, size-1);	
		}
		
		dp_D[size] = 3LL* dp_ABC[size-1] % mod;
		return dp_D[size] ;
	}
			
	if (dp_ABC[size] != INVALID)
		return dp_ABC[size];
	
	if (dp_ABC[size-1] == INVALID)
		dp_ABC[size-1] = solve(0, size-1);
	

	if (dp_D[size-1] == INVALID)
		dp_D[size-1] = solve(1, size-1);
	dp_ABC[size] = (2LL*dp_ABC[size-1] + dp_D[size-1]) % mod;
	return dp_ABC[size];	
	
}

int main() {

	int	n;
	cin >> n;

	dp_D.resize(n + 1, INVALID);
	dp_ABC.resize(n + 1, INVALID);
	
	
	cout << solve(1, n) << "\n";
	return 0;
}