#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
int idx = 0;
bool found =0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    if(s.size()<26){
        cout<<-1;
        return 0;
    }
    map<char,int> mp;
    vector<char> alpha(26);
    // Fill uppercase letters 'A' to 'Z'
    for (char c = 'A'; c <= 'Z'; ++c) {
        alpha[c - 'A'] = c; 
    }
    
    for(int i=0;i<=s.size()-26;i++){
        int cntq =0, cntz=0;
        bool flag =1;
        found =0;
        for(int j=0;j<alpha.size();j++){
            mp[alpha[j]] = 0;
        }
        for(int j=i;j<i+26;j++){
            if(s[j]!='?')
                mp[s[j]]++;
            else{
                cntq++;
            }
        }
        for(int j=0;j<alpha.size();j++){
            if(mp[alpha[j]]==0){
                cntz++;
            }
            else if(mp[alpha[j]]>1){
                flag =0;
                break;
            }
        }
        if(flag==0 || cntq!=cntz){
            found =0;
            continue;    
        }
        else{
            found =1; 
            idx=i;
            break;
        }
    }
        if(!found) cout<<-1;
        else{
            for(int j=idx;j<idx+26;j++){
                if(s[j]=='?'){
                    for(int k=0;k<alpha.size();k++){
                        if(mp[alpha[k]]==0){
                        s[j] = alpha[k];
                        mp[alpha[k]]++;
                        break;
                        }
                    }
                }
            }
            for(int m=0;m<s.size();m++){
                if(s[m]=='?') s[m] = 'B';
                    cout<<s[m];
            }
        }
    
    return 0;
}
