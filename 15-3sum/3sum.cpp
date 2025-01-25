class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) return result;  // If there are fewer than 3 numbers, no triplet can be formed
        
        sort(nums.begin(), nums.end());  // Sort the array
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicates to avoid repeated triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    // Skip duplicates for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                } 
                else if (sum < 0) {
                    ++left;  // We need a larger sum, move left pointer to the right
                } 
                else {
                    --right;  // We need a smaller sum, move right pointer to the left
                }
            }
        }
        
        return result;
    }
};
