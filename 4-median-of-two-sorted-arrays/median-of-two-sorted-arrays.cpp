#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            // Handle edge cases where partitions are out of bounds
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

            // Check if we found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If combined length is even
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else { // If combined length is odd
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Move towards the left in nums1
                high = partitionX - 1;
            } else {
                // Move towards the right in nums1
                low = partitionX + 1;
            }
        }

        // If input arrays are not sorted or invalid
        throw invalid_argument("Input arrays are not sorted or invalid.");
    }
};
