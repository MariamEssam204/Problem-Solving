//https://codeforces.com/problemset/problem/1669/F
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
   int t; cin>>t;
   while(t--){
       int n; cin>>n;
       vector<int> w (n,0);
       for(int i=0;i<n;i++){
           cin>>w[i];
       }
       int l =0; int r=n-1;
       int sumb = 0 ; int suma = 0;
       int res =0;
       bool x =0;
       while(l <= r){
           if(suma >= sumb){
               sumb+=w[l];
               l++;
           }
           else if(suma < sumb){
               suma+=w[r];
               r--;
           }
           if(suma == sumb){
               x = 1;
               res = n-r+l-1;
           }
           
       }
       if(x){
           cout<<res<<"\n";
       }
       else{
           cout<<"0"<<"\n";
       }
       
   }
    return 0;
}
