class Solution:
    def isPalindrome(self, x: int) -> bool:
        
        n = x
        num = 0

        while(n > 0):
            val = (n % 10)
            num = (num * 10) + val
            n = n // 10

        
        if(num == x):
            return True
        
        return False