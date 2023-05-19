class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        addup = 0
        while l < r:
            addup = numbers[l] + numbers[r]
            if addup < target:
                l += 1
            elif addup > target:
                r -= 1
            else:
                return [l + 1, r + 1]