class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        queue<tuple<int,int,int>>q;
        q.push({0 , 0 , 0});

        vector<vector<int>>vis(n , vector<int>(n , 0));
        vis[0][0] = 1;

        int dx[8] = {0 , -1 , -1 , -1 , 0 , +1 , +1 , +1};
        int dy[8] = {-1 , -1 , 0 , +1 , +1 , +1 , 0 , -1};

        while(!q.empty()){

            auto [row , col , steps] = q.front();
            q.pop();

            if(row == n-1 && col == n-1){
                return steps + 1;
            }

            for(int i = 0; i < 8; i++){

                int r = row + dx[i];
                int c = col + dy[i];

                if((r >= 0 && r < n) && (c >= 0 && c < n) && grid[r][c] == 0){

                    if(!vis[r][c]){

                        q.push({r , c , steps + 1});
                        vis[r][c] = 1;
                    }
                }
            }
        }

        return -1;
    }
};