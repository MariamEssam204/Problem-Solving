// https://codeforces.com/contest/2178/problem/B
#include <iostream>
//#include <vector>
#include <string>
using namespace std;
int main() {
    int t=0;
    cin>>t;
    while(t--){
        string s; cin>>s;
        int size = s.size();
        int res =0;
        if(s[size-1] =='u') {
            s[size-1] = 's';
            res++;
        }
        if(s[0]=='u'){
            s[0] = 's';
            res++;
        } 
        for(int i=1;i<size-1;i++){
            if(s[i]=='u'){
                if(s[i-1]==s[i+1]=='s'){
                    continue;
                }
                else if(s[i-1]!='s') {
                    s[i-1]='s';
                    res++;
                }
                else if(s[i+1]!='s') {
                    s[i+1]='s';
                    res++;
                }
            }
        }
       cout<<res<<endl;
    }
    return 0;
}
