class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum3(int k, int n) {
        // find k numbers that sum up to n
        backtracking(1, k, n, 0, 0);
        return ans;
    }

    void backtracking(int start_num, int k, int n, int level, int sum) {
        if (level == k) {
            if (sum == n) {
                ans.push_back(path);
            }
            return;
        }
        for (int i = start_num; i < 10 && n - sum >= i; ++i) {
            path.push_back(i);
            backtracking(i + 1, k, n, level + 1, sum + i);
            path.pop_back();
        }
    }
};