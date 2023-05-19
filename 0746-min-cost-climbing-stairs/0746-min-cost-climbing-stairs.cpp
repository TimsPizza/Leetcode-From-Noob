class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if(size <= 2){
            return min(cost[0], cost[1]);
        }
        int *dp = new int[size + 1]; // representes for minimum costs
        /* INIT */
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i < size + 1; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[size];
    }       
};