#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 
int main() {
    int n, m, x;

    cin >> n >> m;
    
    unordered_set<int> conj;
    vector<int> res(n);
    
    for (auto &a : res) {
        cin >> a;
    }

    for (int i = n-1; i >= 0; --i) {
        if (conj.find(res[i]) == conj.end())
            conj.insert(res[i]);
        res[i] = conj.size();
    }


    for (int i = 0; i < m; ++i) {
        cin >> x;
        cout << res[x-1] << "\n";
    }

}
