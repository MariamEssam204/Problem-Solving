// https://codeforces.com/contest/2167/problem/A
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int a,b,c,d; cin>>a>>b>>c>>d;
        bool x =0;
        if(a==b && a == c && a==d){
                x=1;
            }
        
        if(x){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}
