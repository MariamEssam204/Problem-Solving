class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // Sort the arrays
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        // Find longest consecutive sequence in horizontal bars
        int maxH = 1; // Minimum gap is 1
        int countH = 1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                countH++;
            } else {
                countH = 1;
            }
            maxH = max(maxH, countH);
        }
        
        // Find longest consecutive sequence in vertical bars
        int maxV = 1; // Minimum gap is 1
        int countV = 1;
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                countV++;
            } else {
                countV = 1;
            }
            maxV = max(maxV, countV);
        }
        
        // The gap size is (consecutive removed bars + 1)
        int gap = min(maxH + 1, maxV + 1);
        
        return gap * gap;
    }
};
