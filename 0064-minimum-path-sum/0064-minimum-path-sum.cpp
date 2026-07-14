class Solution {
public:

    int dfs(vector<vector<int>>& grid , int row , int col , int m , int n , vector<vector<int>>& dp){

        if(row == m-1 &&  col == n-1) return grid[m-1][n-1];

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int down = INT_MAX;
        if(row+1 < m){

            down = dfs(grid , row + 1 , col , m , n , dp);
        }

        int right = INT_MAX;
        if(col+1 < n){

            right = dfs(grid , row , col + 1 , m , n , dp);
        }


        dp[row][col] = grid[row][col] + min(down , right);
        
        return dp[row][col];
    }


    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m , vector<int>(n , -1));

        return dfs(grid , 0 , 0 , grid.size() , grid[0].size() , dp);
    }
};