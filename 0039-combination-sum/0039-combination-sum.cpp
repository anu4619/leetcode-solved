class Solution {
public:
void backtrack(int start, int target, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                backtrack(i, target - candidates[i], candidates, combination, result);
                combination.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(0, target, candidates, combination, result);
        return result;
    }
};