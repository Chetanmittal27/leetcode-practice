class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        n = len(nums)

        d = dict()

        for i in range(n):
            remaining = target - nums[i]
            if(d.get(remaining , None) != None):
                return [i , d[remaining]]

            d[nums[i]] = i
        
        return [-1 , -1]