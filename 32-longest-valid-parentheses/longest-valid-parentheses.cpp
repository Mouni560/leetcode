class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // Initialize the stack with a base index for calculation
        int maxLength = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i); // Push the index of '(' onto the stack
            } else {
                stk.pop(); // Pop the last '(' index or base index
                if (stk.empty()) {
                    stk.push(i); // If the stack is empty, push the current index as the new base
                } else {
                    // Calculate the valid substring length
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }

        return maxLength;
    }
};
