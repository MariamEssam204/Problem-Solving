class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        // A 3x3 magic square must be at least 3x3 grid
        if (rows < 3 || cols < 3) return 0;
        
        // Check all possible 3x3 subgrids
        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(grid, i, j)) {
                    count++;
                }
            }
        }
        
        return count;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
        // Check if all numbers are 1-9 and distinct
        vector<bool> seen(10, false);
        
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }
        
        // Calculate sums
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2]; // first row
        
        // Check rows
        for (int i = 0; i < 3; i++) {
            int rowSum = grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2];
            if (rowSum != sum) return false;
        }
        
        // Check columns
        for (int j = 0; j < 3; j++) {
            int colSum = grid[row][col+j] + grid[row+1][col+j] + grid[row+2][col+j];
            if (colSum != sum) return false;
        }
        
        // Check diagonals
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        
        return (diag1 == sum && diag2 == sum);
    }
};
