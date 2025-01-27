class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Check for empty array
        if (nums.empty()) return 0;

        // Initialize a slow pointer
        int slow = 0;

        // Traverse the array with a fast pointer
        for (int fast = 1; fast < nums.size(); ++fast) {
            // When a new unique element is found
            if (nums[fast] != nums[slow]) {
                // Move the slow pointer forward and update the value
                ++slow;
                nums[slow] = nums[fast];
            }
        }

        // Return the number of unique elements
        return slow + 1;
    }
};
