// https://codeforces.com/contest/2179/problem/B
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    cout << fixed << setprecision(0); // output as integer
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long orig = 0;
        for (int i = 0; i < n-1; i++) {
            orig += abs(a[i] - a[i+1]);
        }
        
        long long min_delta = 0; 
        
 
        min_delta = min(min_delta, -(long long)abs(a[0] - a[1]));
        min_delta = min(min_delta, -(long long)abs(a[n-2] - a[n-1]));
 
        for (int k = 1; k < n-1; k++) {
            long long delta = abs(a[k-1] - a[k+1]) - (abs(a[k-1] - a[k]) + abs(a[k] - a[k+1]));
            min_delta = min(min_delta, delta);
        }
        
        long long ans = orig + min_delta;
        cout << ans << "\n";
    }
    
    return 0;
}
