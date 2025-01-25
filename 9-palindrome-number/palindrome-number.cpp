class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: If x is negative or ends with 0 but isn't 0, it's not a palindrome
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        // Step 2: Reverse the second half of the number
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10; // Add the last digit to reversedHalf
            x /= 10; // Remove the last digit from x
        }
        
        // Step 3: Compare the first half and the second half (ignoring the middle digit for odd lengths)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
