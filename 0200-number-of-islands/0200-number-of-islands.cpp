class Solution {
public:

    void dfs(vector<vector<char>>& grid , vector<vector<int>>& vis , int row , int col){

        vis[row][col] = 1;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = row + dx[i];
            int c = col + dy[i];

            if((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size()) && grid[r][c] == '1'){

                if(!vis[r][c]){

                    dfs(grid , vis , r , c);
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] == '1'){

                    q.push({i , j});
                }
            }
        }

        vector<vector<int>>vis(m , vector<int>(n , 0));

        int count = 0;

        while(!q.empty()){

            auto [row , col] = q.front();
            q.pop();

            if(!vis[row][col]){
                count++;
                dfs(grid , vis , row , col);
            }
        }

        return count;
    }
};