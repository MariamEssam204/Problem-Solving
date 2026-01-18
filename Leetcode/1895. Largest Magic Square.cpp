class Solution {
public:
    bool checkwindow(vector<vector<int>>& grid, int i, int j, int k) {
        if (k <= 1) return true; // size 1 is always a magic square
        long long target = 0;
        for (int c = j; c < j + k; c++) {
            target += grid[i][c];
        }
        // try all col
        for (int c = j; c < j + k; c++) {
            long long sum = 0;
            for (int r = i; r < i + k; r++) {
                sum += grid[r][c];
            }
            if (target != sum) {
                return false;
            }
        }
        // try all rows
        for (int r = i; r < i + k; r++) {
            int sum = 0;
            for (int c = j; c < j + k; c++) {
                sum += grid[r][c];
            }
            if (target != sum) {
                return false;
            }
        }
        long long d1 = 0;
        for (int x = 0; x < k; x++) {
            d1 += grid[i + x][j + x];
        }
        if (target != d1) {
            return false;
        }
        long long d2 = 0;
        for (int x = 0; x < k; x++) {
            d2 += grid[i + x][j + k - 1 - x];
        }
        if (target != d2) {
            return false;
        }
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = min(n, m);
        for (int k = maxi; k >= 2; k--) {
            for (int i = 0; i <= n-k; i++) {
                for (int j = 0; j <= m-k; j++) {
                    if (checkwindow(grid, i, j, k)) {
                        return k;
                    }
                }
            }
        }
        return 1;
    }
};
