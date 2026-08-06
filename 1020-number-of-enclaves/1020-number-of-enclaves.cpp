class Solution {
public:

    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int row , int col){
        vis[row][col] = 1;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = row + dx[i];
            int c = col + dy[i];

            if((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size()) && grid[r][c] == 1){

                if(!vis[r][c]){

                    dfs(grid , vis , r , c);
                }
            }
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m , vector<int>(n , 0));

        for(int i = 0; i < m; i++){

            if(grid[i][0] == 1 && !vis[i][0]){

                dfs(grid , vis , i , 0);
            }

            if(grid[i][n-1] == 1 && !vis[i][n-1]){

                dfs(grid , vis , i , n - 1);
            }
        }


        for(int i = 0; i < n; i++){

            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(grid , vis , 0 , i);
            }

            if(grid[m-1][i] == 1 && !vis[m-1][i]){
                dfs(grid , vis , m-1 , i);
            }
        }


        int count = 0;

        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1 && vis[i][j] == 0){

                    count++;
                }
            }
        }

        return count;
    }
};