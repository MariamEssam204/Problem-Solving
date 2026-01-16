//https://cses.fi/problemset/task/1646
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,q;
    cin>>n>>q;
    vector<long long> arr (n+1,0);
    vector<long long> prefix (n+1,0);
    
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(long long i=1;i<=n;i++){
       prefix[i] = arr[i]+prefix[i-1];
    }
    while(q--){
        long long a,b;
        long long res=0;
        cin>>a>>b;
        res = prefix[b]-prefix[a-1];
        cout<<res<<"\n";
    }
    return 0;
}
