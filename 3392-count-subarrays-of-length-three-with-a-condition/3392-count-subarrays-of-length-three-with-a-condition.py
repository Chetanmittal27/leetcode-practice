class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        
        count = 0
        n = len(nums)

        l , r = 0 , 2

        while(r < n):
            mid = (l + r) // 2
            sum = nums[l] + nums[r]
            half = nums[mid] / 2
            
            if(sum == half):
                count = count + 1
            
            l = l + 1
            r = r + 1

        return count