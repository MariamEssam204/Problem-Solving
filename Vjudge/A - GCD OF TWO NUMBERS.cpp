// A - GCD OF TWO NUMBERS 
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
    ll m,n;cin>>m>>n;
    ll res = __gcd(m,n);
    cout<<res<<"\n";
    return 0;
}
