class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen; // This will store the seen elements as strings like "row_#_val", "col_#_val", "box_#_val"
        
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') {
                    char num = board[row][col];
                    
                    // Check if the number has already appeared in the row, column, or sub-box
                    string rowKey = "row_" + to_string(row) + "_" + num;
                    string colKey = "col_" + to_string(col) + "_" + num;
                    string boxKey = "box_" + to_string(row / 3 * 3 + col / 3) + "_" + num;
                    
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }
                    
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }
        
        return true;
    }
};
