//https://vjudge.net/problem/CSES-1069
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin>>s;
    int size = s.size();
    int l=0,r=0;
    int maxlen = 1;
    while(r<size){
        if(s[r]!=s[l]){
            l=r;
        }
        maxlen = max(maxlen, r-l+1 );
        r++;
    }
    cout<<maxlen;
    return 0;
}
