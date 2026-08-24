class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        q = deque()
        freshOranges = 0

        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            
            for j in range(n):

                if(grid[i][j] == 1):
                    freshOranges += 1

                elif(grid[i][j] == 2):
                    q.append((i , j))

        
        time = 0

        dx = [0 , -1 , 0 , +1]
        dy = [-1 , 0 , +1 , 0]

        while(len(q) > 0 and freshOranges > 0):

            num = len(q)

            time = time + 1

            for i in range(num):

                row , col = q.popleft()

                for j in range(4):

                    r = row + dx[j]
                    c = col + dy[j]

                    if((r >= 0 and r < m) and (c >= 0 and c < n) and grid[r][c] == 1):

                        grid[r][c] = 2
                        freshOranges = freshOranges - 1
                        q.append((r , c))

        
        if(freshOranges == 0):
            return time
        
        return -1