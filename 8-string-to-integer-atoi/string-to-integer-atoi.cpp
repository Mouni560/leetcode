class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') i++;

        // Step 2: Determine the sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Extract the number
        long result = 0; // Use long to detect overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // Step 4: Check for overflow
            if (result * sign <= INT_MIN) return INT_MIN;
            if (result * sign >= INT_MAX) return INT_MAX;
            i++;
        }

        // Step 5: Return the result with sign
        return result * sign;
    }
};
