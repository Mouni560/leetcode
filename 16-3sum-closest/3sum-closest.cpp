class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the input array to use the two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Initialize the result to a large number
        int closestSum = nums[0] + nums[1] + nums[2];  // Use the first triplet as the initial closest sum
        
        // Iterate through the array
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicate numbers for the current position to avoid repetitive triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                // Calculate the current sum
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update the closestSum if the current sum is closer to the target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // If current sum is less than the target, we need a larger sum, so move left pointer to the right
                if (currentSum < target) {
                    ++left;
                } 
                // If current sum is greater than the target, we need a smaller sum, so move right pointer to the left
                else if (currentSum > target) {
                    --right;
                } 
                // If the current sum is exactly the target, we can return the sum immediately
                else {
                    return currentSum;
                }
            }
        }
        
        return closestSum;
    }
};
