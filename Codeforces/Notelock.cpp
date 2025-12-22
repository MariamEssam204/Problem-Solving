//https://codeforces.com/contest/2154/problem/A
#include <iostream>
#include <string>
using namespace std;
int main() {
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        k--;
        string s; cin>>s;
        int pro =0;
        if(s[0]=='1'){
            pro++;
        }
        for(int i=1;i<n;i++){
            bool x = false;
            if(s[i]=='1'){
                int index = 0;
                if(k>i){
                    index =0;
                }
                else if(k==i){
                    index=0;
                }
                else{
                    index =i-k;
                }
                for(int j=i-1;j>=index;j--){
                    if(s[j]!='1'){
                        x = true ;
                    }
                    else{
                        x= false;
                        break;
                    }
                }
                
            }
            if(x){
                    pro++;
                }
        }
        cout<<pro<<endl;
    }
    return 0;
}
