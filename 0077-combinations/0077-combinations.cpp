class Solution {
public:
    vector<int> nums;
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        for (int i = 0; i < n; ++i) {
            nums.push_back(i + 1);
        }
        // initialize the nums
        backtracking(0, n, k);
        return ans;
    }

    void backtracking(int start_index, int n, int k) {
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = start_index; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtracking(i + 1, n, k);
            path.pop_back();
        }
    }
};


