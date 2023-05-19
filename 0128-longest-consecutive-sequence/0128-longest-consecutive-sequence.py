class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        ans = 0
        for i in nums:
            if i - 1 not in num_set: 
                # to avoid redundant comparisons
                # only compare element has larger consecutive ones
                step = 1
                while i + step in num_set:
                    step += 1
                ans = max(ans, step)
        return ans