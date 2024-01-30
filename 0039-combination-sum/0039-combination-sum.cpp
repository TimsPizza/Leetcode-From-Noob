class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtracking(candidates, 0, target, 0);
        return ans;
    }

    void backtracking(vector<int> &candidates, int start_index, int target, int sum) {
        if (sum >= target) {
            if (sum == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = start_index; i < candidates.size(); ++i) {
            if (candidates[i] + sum <= target) {
                path.push_back(candidates[i]);
                backtracking(candidates, i, target, sum + candidates[i]);
                path.pop_back();

            }
        }

    }
};