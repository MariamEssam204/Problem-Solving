//https://cses.fi/problemset/task/1083
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> freq(n+1,0);
    freq[0] =1;
    for(int i=1;i<n;i++){
        int x;cin>>x;
        freq[x]++;
    }
    for(int i=0;i<=n;i++){
        if(freq[i]==0){
            cout<<i;
            break;
        }
    }
    return 0;
}
