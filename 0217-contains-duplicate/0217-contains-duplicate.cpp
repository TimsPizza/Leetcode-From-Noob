class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
        {
            return false;
        }
        unordered_map<int, int> hash;
        for(int i = 0; i < size; ++i)
        {
            hash[nums[i]] += 1;
            if(hash[nums[i]] == 2)
            {
                return true;
            }
        }
        return false;
    }
};