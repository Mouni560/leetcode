#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0, maxLength = 0;

        // Helper function to expand around a center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1; // Length of the palindrome
        };

        for (int i = 0; i < n; ++i) {
            // Odd-length palindromes
            int len1 = expandAroundCenter(i, i);
            // Even-length palindromes
            int len2 = expandAroundCenter(i, i + 1);
            // Find the longer of the two
            int len = max(len1, len2);

            // Update the start and maxLength if a longer palindrome is found
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2; // Adjust start index
            }
        }

        return s.substr(start, maxLength);
    }
};
