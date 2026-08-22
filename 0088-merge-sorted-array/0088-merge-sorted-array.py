class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        
        temp = []

        left , right = 0 , 0

        while(left < m and right < n):
            if(nums1[left] <= nums2[right]):
                temp.append(nums1[left])
                left = left + 1

            else:
                temp.append(nums2[right])
                right = right + 1
        

        while(left < m):
            temp.append(nums1[left])
            left = left + 1
        
        while(right < n):
            temp.append(nums2[right])
            right = right + 1

        
        for i in range(m+n):
            nums1[i] = temp[i]

            