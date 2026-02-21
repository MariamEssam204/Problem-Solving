//https://codeforces.com/problemset/problem/295/A
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, k;
    cin >> n >> m >> k;
    
    // Read initial array
    vector<ll> arr(n + 1, 0);
    for (ll i = 1; i <= n; i++) 
        cin >> arr[i];
    
    // Store all operations in separate arrays
    vector<ll> opL(m + 1, 0);
    vector<ll> opR(m + 1, 0);
    vector<ll> opVal(m + 1, 0);
    
    for (ll i = 1; i <= m; i++) {
        cin >> opL[i] >> opR[i] >> opVal[i];
    }
    
    // Track how many times each operation is applied
    vector<ll> op_count(m + 2, 0);
    for (ll i = 0; i < k; i++) {
        ll l, r;
        cin >> l >> r;
        op_count[l]++;
        op_count[r + 1]--;
    }
    
    // Prefix sum to get final operation counts
    for (ll i = 1; i <= m; i++) {
        op_count[i] += op_count[i - 1];
    }
    
    // Apply operations to difference array
    vector<ll> diff(n + 2, 0);
    for (ll i = 1; i <= m; i++) {
        if (op_count[i] > 0) {
            ll total = opVal[i] * op_count[i];
            diff[opL[i]] += total;
            diff[opR[i] + 1] -= total;
        }
    }
    
    // Prefix sum to get final array
    for (ll i = 1; i <= n; i++) {
        diff[i] += diff[i - 1];
        cout << arr[i] + diff[i] << " ";
    }
    
    return 0;
}
