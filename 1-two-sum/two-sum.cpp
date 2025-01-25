#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // To store numbers and their indices
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            // Check if the complement is already in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            // Store the number and its index
            num_map[nums[i]] = i;
        }
        return {}; // Edge case: if no solution exists (not possible as per constraints)
    }
};
