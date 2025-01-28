class Solution {
public:
    void findCombinations(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target becomes 0, add the current combination to the result
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Iterate through candidates starting from 'index'
        for (int i = index; i < candidates.size(); i++) {
            // Skip if the current candidate exceeds the target
            if (candidates[i] > target) continue;
            
            // Include the candidate and recurse
            current.push_back(candidates[i]);
            findCombinations(i, target - candidates[i], candidates, current, result);
            
            // Backtrack: remove the last element
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};
