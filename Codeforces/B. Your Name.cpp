// https://codeforces.com/contest/2167/problem/B
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
        int n; cin>>n;
        string s , t; cin>>s>>t;
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for (int i = 0; i < s.size(); i++) {
            freq1[s[i]-97] ++;
        }
        for (int i = 0; i < t.size(); i++) {
            freq2[t[i]-97] ++;
        }
        bool x =1;
        for (int i = 0; i < 26; i++) {
            if(freq1[i]!=freq2[i]){
                x = 0;
                break;
            }
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
