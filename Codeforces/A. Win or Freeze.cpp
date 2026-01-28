// https://codeforces.com/problemset/problem/150/A
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iostream>
#define ll long long
using namespace std;
//Prime factorization
vector<long long> primeFactorization(long long n) {
    vector<long long> factors;
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        factors.push_back(n);
        n = 1;
    }
    return factors;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin >> n;
    vector<ll> factors = primeFactorization(n);
    if(n==1 || factors.size() < 2){
        cout<<"1\n";
        cout<<"0"<<"\n";
    }
    
    else if(factors.size() ==2){
        cout<<"2\n";
    }
    else{
        cout<<"1\n";
        cout<<factors[0]*factors[1]<<"\n";
    }
    return 0;
}
