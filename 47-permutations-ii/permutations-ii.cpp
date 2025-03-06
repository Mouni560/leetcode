class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        // If the current permutation is the same size as the nums array, we've found a valid permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
                continue;
            }
            
            // Choose the element nums[i] and explore further
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, result, current, used);
            // Backtrack: undo the choice
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        // Sort the array to make sure duplicates are adjacent
        sort(nums.begin(), nums.end());
        
        backtrack(nums, result, current, used);
        return result;
    }
};
