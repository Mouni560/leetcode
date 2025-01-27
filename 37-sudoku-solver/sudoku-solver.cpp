class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // Find an empty cell
                if (board[i][j] == '.') {
                    // Try digits '1' to '9'
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num; // Try placing the number
                            if (solve(board)) {
                                return true; // If valid, continue solving
                            }
                            board[i][j] = '.'; // Backtrack if no valid solution
                        }
                    }
                    return false; // If no number can fit in this cell, backtrack
                }
            }
        }
        return true; // Solved
    }
    
    bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
        // Check the row
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == num) return false;
        }
        
        // Check the column
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num) return false;
        }
        
        // Check the 3x3 sub-box
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (board[i][j] == num) return false;
            }
        }
        
        return true;
    }
};
