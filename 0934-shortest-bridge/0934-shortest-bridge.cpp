class Solution {
public:

    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , queue<tuple<int,int,int>>& q , int row , int col){

        vis[row][col] = 1;
        q.push({row , col , 0});

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = row + dx[i];
            int c = col + dy[i];

            if((r >= 0 && r < grid.size()) && (c >= 0 && c < grid.size()) && grid[r][c] == 1){

                if(!vis[r][c]){

                    dfs(grid , vis , q , r , c);
                }
            }
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int startRow = -1 , startCol = -1;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){

                    startRow = i;
                    startCol = j;
                    break;
                }

                if(startRow != -1 && startCol != -1){
                    break;
                }
            }
        }

        vector<vector<int>>vis(n , vector<int>(n , 0));

        queue<tuple<int,int,int>>q;

        dfs(grid , vis , q , startRow , startCol);

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        while(!q.empty()){

            auto [row , col , steps] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){

                int r = row + dx[i];
                int c = col + dy[i];

                if((r >= 0 && r < n) && (c >= 0 && c < n)){

                    if(grid[r][c] == 1 && !vis[r][c]){
                        return steps;
                    }

                    if(grid[r][c] == 0 && !vis[r][c]){
                        grid[r][c] = 1;
                        vis[r][c] = 1;
                        q.push({r , c , steps + 1});
                    }
                }
            }
        }

        return 0;
    }
};