class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = new int[2];
        HashMap<Integer, Integer> tab = new HashMap<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            tab.put(target - nums[i], i);
        }
        for (int i = 0; i < nums.length; i++) {
            if (tab.containsKey(nums[i]) && tab.get(nums[i]) != i) {
                ans[0] = i;
                ans[1] = tab.get(nums[i]);
                break;
            }
        }
        return ans;
    }
}