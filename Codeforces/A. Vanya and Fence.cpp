// A. Vanya and Fence
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n,h;cin>>n>>h;
   vector<int> arr(n,0);
   for(int i=0;i<n;i++) cin>>arr[i];
   ll sum =0;
    for(int i=0;i<n;i++){
        if(arr[i]<= h) sum++;
        else{
            sum+=2;
        }
    }
    cout<<sum;
    return 0;
}
