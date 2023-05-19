class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return false;
        }
        if(size == 1)
        {
            return true;
        }
        int dp[2] = {0}; // represents max reacheable index
        dp[0] = nums[0];       // dp[i] = max(dp[i-1], nums[i] + i)
        for (int i = 1; i < size; i++)
        {
            if (dp[0] >= i)
            {
                dp[1] = max(dp[0], nums[i] + i);
                dp[0] = dp[1];
            }
            else
            {
                return false;
            }
        }
        return dp[1] >= size - 1;
    }
};