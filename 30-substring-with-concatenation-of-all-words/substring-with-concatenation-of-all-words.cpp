class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;

        if (s.size() < substringLength) return result;

        // Create a frequency map for the words
        unordered_map<string, int> wordMap;
        for (const string& word : words) {
            wordMap[word]++;
        }

        // Traverse the string in windows
        for (int i = 0; i < wordLength; i++) {
            int left = i, right = i;
            unordered_map<string, int> seenWords;
            int count = 0;

            while (right + wordLength <= s.size()) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordMap.find(word) != wordMap.end()) {
                    seenWords[word]++;
                    count++;

                    // If word appears more times than expected, move the left pointer
                    while (seenWords[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // If all words are matched
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // If word is not in wordMap, reset the window
                    seenWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
