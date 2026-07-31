class Solution {
public:

    void dfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int start , int end , queue<pair<int,int>>& q){

        vis[start][end] = 1;
        q.push({start , end});

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = start + dx[i];
            int c = end + dy[i];

            if((r >= 0 && r < grid.size()) && (c >= 0 && c < grid[0].size()) && grid[r][c] == 1){

                if(!vis[r][c]){
                    dfs(grid , vis , r , c , q);
                }
            }
        }
    }


    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();

        vector<vector<int>>vis(n , vector<int>(n , 0));

        queue<pair<int , int>>q;

        int start = -1 , end = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    start = i;
                    end = j;
                    break;
                }
            }

            if(start != -1 && end != -1){
                break;
            }
        }


        dfs(grid , vis , start , end , q);

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        int ans = 0;

        while(!q.empty()){

            int len = q.size();

            ans++;

            for(int i = 0; i < len; i++){

                auto p = q.front();
                q.pop();

                int row = p.first;
                int col = p.second;

                for(int j = 0; j < 4; j++){

                    int r = row + dx[j];
                    int c = col + dy[j];

                    if((r >= 0 && r < n) && (c >= 0 && c < n)){

                        if(grid[r][c] == 1 && !vis[r][c]){
                            return ans-1;
                        }

                        if(grid[r][c] == 0 && !vis[r][c]){
                            vis[r][c] = 1;
                            q.push({r , c});
                        }
                    }
                }
            }
        }

        return ans-1;
    }
};