class Solution {
public:

    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int row , int col , int &count){

        vis[row][col] = 1;
        count++;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = row + dx[i];
            int c = col + dy[i];

            if((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size()) && grid[r][c] == 1){

                if(!vis[r][c]){
                    dfs(grid , vis , r , c , count);
                }
            }
        }
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;

        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    q.push({i , j});
                }
            }
        }

        int maxArea = 0;

        vector<vector<int>>vis(m , vector<int>(n , 0));

        while(!q.empty()){

            auto [row , col] = q.front();
            q.pop();

            if(!vis[row][col]){

                int count = 0;

                dfs(grid , vis , row , col , count);

                maxArea = max(maxArea , count);
            }
        }

        return maxArea;
    }
};