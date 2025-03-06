class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize the number of jumps, current_end, and farthest
        int jumps = 0, current_end = 0, farthest = 0;
        
        // We iterate through all elements except the last one
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest we can reach
            farthest = max(farthest, i + nums[i]);
            
            // If we've reached the end of the current jump range
            if (i == current_end) {
                jumps++;  // Increment jumps
                current_end = farthest;  // Move the end of the current jump range
                
                // If we can reach or exceed the last index, return the number of jumps
                if (current_end >= n - 1) {
                    return jumps;
                }
            }
        }
        
        return jumps;  // This line should never be reached due to the problem guarantee
    }
};
