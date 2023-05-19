class Solution {
public:
    int tribonacci(int n) {
        int dp[4] = {0, 1, 1, -1};
        if(n < 3){
            return dp[n];
        }
        for(int i = 3; i <= n; ++i){
            dp[3] = dp[0] + dp[1]+ dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};