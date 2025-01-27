class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer for the position to place elements not equal to val

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k++] = nums[i]; // Place the non-val element at the k-th position
            }
        }

        return k; // Return the count of elements not equal to val
    }
};
