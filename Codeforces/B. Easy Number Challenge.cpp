// Online C++ compiler to run C++ program online
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c ; cin>>a>>b>>c;
    int N = a*b*c;
    vector<ll> div(N+1,0);
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            div[j]++;
        }

    }
    ll sum =0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                sum += div[(i+1)*(j+1)*(k+1)];
            }
        }
    }
    cout<<sum%1073741824<<endl;
    return 0;
}
