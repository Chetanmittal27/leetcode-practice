class Solution:
    def checkDivisibility(self, n: int) -> bool:
        sum = 0
        product = 1

        num = n

        while(num > 0):
            val = (num % 10)
            sum = sum + val
            product = product * val
            num = num // 10

        
        total = sum + product
        print(total)

        if(n % total == 0):
            return True
        
        return False