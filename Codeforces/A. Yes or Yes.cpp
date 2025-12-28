// https://codeforces.com/contest/2178/problem/A
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int t=0;
    cin>>t;
    while(t--){
        string s; cin>>s;
        int size = s.size();
        vector<bool> x;
        for(int i=0;i<size;i++){
            if(s[i]=='N'){
                x.push_back(0);
            }
            else{
                 x.push_back(1);
            }
        }
        int sizevec = size;
        for(int i=0;i<size-1;i++){
            if(x[i]&&x[i+1]){
                continue;
            }
            else{
                sizevec--;
                x[i+1] = x[i]| x[i+1];
                x[i]=0;
            }
        }
        //for(int i=0;i<size-1;i++){
          //  cout<<x[i]<<",";
       // }cout<<endl;
        
        bool res =true;
        for(int i=0;i<size-1;i++){
            if(x[i]==1){
                res = false;
                break;
            }
        }
        if(res)
        cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
