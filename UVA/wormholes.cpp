#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int nTests = 1;
	cin >> nTests;
	
	int INF = INT_MAX;
	
	vector<tuple<int, int, int>> edgeList;
	int distances[1001];
		
	int n, m;
	int x, y, t;
	
	bool thereIsNegativeCycle;
	
	for (int k=1; k<=nTests; ++k) {
		thereIsNegativeCycle = false;
		edgeList.clear();
		
		cin >> n >> m;
		
		for (int i=0;i< m; ++i) {
			cin >> x >> y >> t;
			edgeList.push_back({x, y, t});
		}
	
		/**for (auto v: edgeList) {
			tie(x, y, t) = v;
			cerr << "(" << x << ", " << y <<  ", " << t << ") \n";
		}
		cerr << "\n";*/
		
		for (int i=0;i< n; ++i) distances[i] = INF;
		distances[0] = 0;
		for (int i=0;i< n-1; ++i) {
			for(auto e: edgeList ){
				tie(x, y, t) = e;
				distances[y] = min(distances[y], distances[x]+t);
			}
		}
		
		for(auto e: edgeList ){
			tie(x, y, t) = e;
			
			if (distances[x]+t < distances[y]) {
				thereIsNegativeCycle = true;
				break;
			}
		}
		
		if (thereIsNegativeCycle) cout << "possible\n";
		else cout << "not possible\n";
	}
	
	return 0;
}
