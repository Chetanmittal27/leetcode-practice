class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        
        n = len(nums)

        s = set(nums)

        if(len(s) < 3):
            return max(s)

        return sorted(s , reverse = True)[2]