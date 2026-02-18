#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#define ll long long
using namespace std;
int idx = 0;
bool found =0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     // Open input file
    ifstream fin("paintbarn.in");
    // Open output file
    ofstream fout("paintbarn.out");
    
    int n, k;
    fin >> n >> k;
    
    vector<vector<int>> matrix(1e3+1,vector<int>(1e3+1 ,0));
    vector<vector<int>> arr(n,vector<int>(4 ,0));
    for(int i =0;i<n;i++){
        for(int j=0;j<4;j++){
            fin>>arr[i][j];
        }
    }
    for(int i =0;i<n;i++){
        int x1 = arr[i][0];
        int y1 = arr[i][1];
        int x2 = arr[i][2];
        int y2 = arr[i][3];
        matrix[x1+1][y1+ 1] ++;
        matrix[x1+1][y2 + 1] --;
        matrix[x2 + 1][y1+ 1] --;
        matrix[x2 + 1][y2 + 1] ++;
        
    }
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 1; j < matrix[0].size(); j++) {
            matrix[i][j] += matrix[i][j-1]; // prefixSum of each row
    }
}
    for(int i = 1; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] += matrix[i-1][j]; // prefixSum of each column
    }
}
    ll cnt =0;
    for( int row=0;row<matrix.size();row++){
        for(int col =0;col <matrix[0].size();col++){
            if(matrix[row][col]==k){
                cnt++;
            }
        }
    }
    fout << cnt << "\n";
    
    // Close files
    fin.close();
    fout.close();
    return 0;
}
