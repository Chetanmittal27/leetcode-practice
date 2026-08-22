class Solution:
    def smallestNumber(self, num: int) -> int:
        
        if(num == 0):
            return 0

        arr = []
        x = abs(num)

        count = 0

        while(x > 0):
            val = (x % 10)
            if(val == 0):
                count = count + 1
            else:
                arr.append(val)
            
            x = x // 10

        
        arr.sort()

        ans = 0

        if(num < 0):
            for i in range(len(arr)-1 , -1 , -1):
                ans = (ans * 10) + arr[i]
            
            ans = ans * pow(10 , count)
            return ans * (-1)
        

        ans = arr[0]
        ans = ans * pow(10 , count)

        for i in range(1 , len(arr)):
            ans = (ans * 10) + arr[i]

        return ans
