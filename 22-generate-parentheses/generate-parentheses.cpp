class Solution {
public:
    void backtrack(string& current, int open, int close, int n, vector<string>& result) {
        // If the current string is a valid parentheses string, add it to result
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // Add opening parenthesis if we have not yet added n opening parentheses
        if (open < n) {
            current.push_back('(');
            backtrack(current, open + 1, close, n, result);
            current.pop_back();  // backtrack
        }
        
        // Add closing parenthesis if there are more opening parentheses than closing ones
        if (close < open) {
            current.push_back(')');
            backtrack(current, open, close + 1, n, result);
            current.pop_back();  // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(current, 0, 0, n, result);
        return result;
    }
};
