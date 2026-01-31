//https://codeforces.com/problemset/problem/1742/D
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
    int t;cin>>t;
    
    while(t--){
        int n;cin>>n;
        vector<int>a(n+1);
        map<int,int>mp;
        int maxi = 0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp[a[i]] = i;
        }
        for(int i=1;i<=1000;i++){
            for(int j=i;j<=1000;j++){
                if(mp[i]!=0 && mp[j]!=0 && gcd(i,j)==1){
                    maxi = max(maxi,mp[i]+mp[j]);
                }
            }
        }
        
        if(maxi==0) maxi =-1;
        cout<<maxi<<"\n";
}
    return 0;
}
