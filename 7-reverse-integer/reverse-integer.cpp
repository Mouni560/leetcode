class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10; // Extract the last digit
            x /= 10;           // Remove the last digit
            
            // Check for overflow before appending the digit
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            
            result = result * 10 + digit; // Append the digit
        }
        return result;
    }
};
