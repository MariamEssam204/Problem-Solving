#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <stack>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;cin>>n;
        string s; cin>>s;
        int res =0;
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                res++;
                arr.push_back(i+1);
            }
        }
        cout << res << "\n";
        for(auto x : arr){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
