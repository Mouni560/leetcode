class Solution {
public:
    string countAndSay(int n) {
        // Start with the first term in the sequence
        string result = "1";
        
        // Generate the sequence up to the nth term
        for (int i = 2; i <= n; ++i) {
            string temp = "";
            int count = 1;
            
            // Iterate over the current result to build the next term
            for (int j = 1; j < result.size(); ++j) {
                // If the current digit is the same as the previous, increment count
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    // If digits differ, append the count and the previous digit
                    temp += to_string(count) + result[j - 1];
                    count = 1;  // Reset count for the new digit
                }
            }
            // Don't forget to add the last counted digit
            temp += to_string(count) + result[result.size() - 1];
            
            // Update result to the new term in the sequence
            result = temp;
        }
        
        return result;
    }
};
