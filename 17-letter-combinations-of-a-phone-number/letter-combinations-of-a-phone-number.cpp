class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // Return empty vector if input is empty

        // Map digits to their corresponding letters
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;  // To store the result combinations
        string current;  // To build the current combination

        // Backtracking function to generate combinations
        backtrack(digits, 0, current, result, mapping);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string& current, vector<string>& result, const vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);  // When the current combination is complete, add it to result
            return;
        }

        int digit = digits[index] - '0';  // Convert digit character to integer
        const string& letters = mapping[digit];  // Get corresponding letters for this digit

        // Explore each letter for the current digit
        for (char letter : letters) {
            current.push_back(letter);  // Add the letter to the current combination
            backtrack(digits, index + 1, current, result, mapping);  // Recur for the next digit
            current.pop_back();  // Backtrack to remove the last added letter
        }
    }
};
