class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return result;

        sort(nums.begin(), nums.end());  // Sort the array to facilitate two-pointer method

        for (int i = 0; i < nums.size() - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size() - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    // Use long long for the sum to avoid overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;  // We need a larger sum, so move left pointer to the right
                    } else {
                        --right;  // We need a smaller sum, so move right pointer to the left
                    }
                }
            }
        }

        return result;
    }
};
