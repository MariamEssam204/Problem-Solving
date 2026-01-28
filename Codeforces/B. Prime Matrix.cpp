// https://codeforces.com/problemset/problem/271/B
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
vector<ll> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    vector<ll> primes;
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            if (i <= n / i) { // Same as i*i <= n
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
                }
            }
        }
    }
    return primes;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n,m;cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<ll> primes = sieve(1e6);
    ll min_cnt =LONG_MAX;
    ll cnt_row , cnt_col;
    for(int i=0;i<n;i++){
        cnt_row = 0;
        for(int j=0;j<m;j++){
            auto it = lower_bound(primes.begin(),primes.end(),matrix[i][j]);
            ll res = *it - matrix[i][j];
            cnt_row += res;
        }
        min_cnt = min(min_cnt,cnt_row);
    }
    for(int j=0;j<m;j++){
        cnt_col= 0;
        for(int i=0;i<n;i++){
            auto it = lower_bound(primes.begin(),primes.end(),matrix[i][j]);
            ll res = *it - matrix[i][j];
            cnt_col += res;
        }
        min_cnt = min(min_cnt,cnt_col);
    }
    cout<<min_cnt;
    return 0;
}
