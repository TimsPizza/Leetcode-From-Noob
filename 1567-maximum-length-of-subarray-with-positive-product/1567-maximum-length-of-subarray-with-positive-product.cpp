class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
        {
            return nums[0] > 0 ? 1 : 0;
        }
        int dp_unpositive[2] = {0}; // count of pos or neg sub len at index i
        int dp_positive[2] = {0};
        int ans = 0, temp = 0;
        dp_unpositive[0] = nums[0] < 0;
        dp_positive[0] = nums[0] > 0;
        for (int i = 1; i < size; i++)
        {
            if(nums[i] > 0)
            {
                dp_positive[1] = dp_positive[0] + 1;
                dp_unpositive[1] = dp_unpositive[0] > 0 ? dp_unpositive[0] + 1 : 0;;
            }
            else if(nums[i] < 0)
            {
                dp_positive[1] = dp_unpositive[0] > 0 ? dp_unpositive[0] + 1 : 0;
                dp_unpositive[1] = dp_positive[0] + 1;
            }
            else
            {
                dp_positive[1] = dp_unpositive[1] = 0;
            }
            ans = max(dp_positive[1], ans);
            dp_positive[0] = dp_positive[1];
            dp_unpositive[0] = dp_unpositive[1];
        }
        return ans;
    }
};