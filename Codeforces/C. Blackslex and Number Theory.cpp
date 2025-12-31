//https://codeforces.com/contest/2179/problem/C
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end());
        
        int m1 = a[0];
        int m2 = a[1];
        int diff = m2 - m1;
        
        if (diff > m1) {
            cout << diff << "\n";
        } else {
            cout << m1 << "\n";
        }
    }
    
    return 0;
}
