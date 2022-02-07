#include<bits/stdc++.h>
using namespace std;

void solve(int n, int div) {
	
	if (n <= 2)  {
		cout << "NO\n";
		return ; 
	}
	
	
	if (div == n) {
		if ((n-div) %2 == 0 && div %2 == 0) {
			cout << "YES\n";
			return ; 
		}
		
		else {
			cout << "NO\n";
			return ; 
		}
	}
	
	if ((n-div) %2 == 0 && div %2 == 0) {
		cout << "YES\n";
		return ; 
	}

	return solve(n, div+1);	
	
}

int main() {
	int n;
	cin >> n;
	
	
	solve(n, 1);
	
	return 0;
}