//https://codeforces.com/problemset/problem/1638/B
//Arrays can cause stack overflow if too large
//Vectors allocate on heap (safer for large sizes)
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool canSort = true;
        int lastEven = 0;
        int lastOdd = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                if(a[i] < lastEven) {
                    canSort = false;
                    break;
                }
                lastEven = a[i];
            } else {
                if(a[i] < lastOdd) {
                    canSort = false;
                    break;
                }
                lastOdd = a[i];
            }
        }
        
        cout << (canSort ? "Yes" : "No") << "\n";
    }
    
    return 0;
}
