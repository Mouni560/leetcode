class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // target found at mid index
            } else if (nums[mid] < target) {
                left = mid + 1;  // move right
            } else {
                right = mid - 1;  // move left
            }
        }
        
        // If target is not found, left will be the insertion position
        return left;
    }
};
