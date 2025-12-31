// https://codeforces.com/contest/2179/problem/A
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int k,x; cin>>k>>x;
        long long res = k*x;
        res+=1;
        cout<<res<<endl;
        
    }
    return 0;
}
