// A. Complicated GCD
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
//GCD
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b; cin>>a>>b;
    if(a!=b)
    cout<<1;
    else{
        cout<<a;
    }
    return 0;
}
