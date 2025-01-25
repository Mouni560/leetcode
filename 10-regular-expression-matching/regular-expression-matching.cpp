class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        
        // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;  // Both the string and pattern are empty
        
        // Handle patterns like a*, a*b*, etc., where empty string can match patterns
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2]; // If we have a '*' we check the pattern before it
            }
        }
        
        // Fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    // If characters match or pattern has '.', copy the diagonal value
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // Case 1: Ignore '*' and the character before it
                    dp[i][j] = dp[i][j-2];
                    // Case 2: If the character before '*' matches s[i-1] or it is a '.', take the value from dp[i-1][j]
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};