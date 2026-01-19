class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        bool x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] <= threshold) {
                    x = 1;
                    break;
                }
            }
        }
        if (!x)
            return 0;
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));

        // Build prefix sum matrix correctly
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
        int area = 1;
        for (int w = 2; w <= min(m, n); w++) {
            for (int i = 0; i <= n - w; i++) {
                for (int j = 0; j <= m - w; j++) {
                    long long x = prefix[i+w][j+w] - prefix[i][j+w] -
                                  prefix[i+w][j] + prefix[i][j];

                    if (x <= threshold) {
                        area = max(area, w);
                    }
                }
            }
        }
        return area;
    }
};
