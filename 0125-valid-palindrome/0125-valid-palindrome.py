class Solution:
    def isPalindrome(self, s: str) -> bool:
        regex = re.compile('[^a-zA-Z0-9]')
        s1 = regex.sub('', s).lower()
        l = 0
        r = len(s1) - 1
        while l < r:
            if s1[l] != s1[r]:
                return False
            l += 1
            r -= 1
        return True