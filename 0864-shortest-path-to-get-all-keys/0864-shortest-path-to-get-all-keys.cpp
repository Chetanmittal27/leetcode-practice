class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int start = -1 , end = -1;
        int totalKeys = 0;

        // find start and count keys
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '@'){
                    start = i;
                    end = j;
                }
                else if(isalpha(grid[i][j]) && islower(grid[i][j])){
                    totalKeys = max(totalKeys, grid[i][j] - 'a' + 1);
                }
            }
        }

        // visited[row][col][mask]
        vector<vector<vector<int>>> vis(m , vector<vector<int>>(n , vector<int>(1 << totalKeys , 0)));

        queue<tuple<int,int,int,int>> q;
        q.push({start , end , 0 , 0});
        vis[start][end][0] = 1;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        while(!q.empty()){

            auto [row , col , steps , mask] = q.front();
            q.pop();

            if(mask == (1 << totalKeys) - 1){
                return steps;
            }

            for(int i = 0; i < 4; i++){

                int r = row + dx[i];
                int c = col + dy[i];

                if((r >= 0 && r < m) && (c >= 0 && c < n) && grid[r][c] != '#'){

                    char cell = grid[r][c];
                    int newMask = mask;

                    if(isalpha(cell) && islower(cell)){
                        newMask |= (1 << (cell - 'a'));
                    }

                    if(isalpha(cell) && isupper(cell)){
                        if(!(mask & (1 << (cell - 'A')))){
                            continue; // door locked
                        }
                    }

                    if(!vis[r][c][newMask]){
                        vis[r][c][newMask] = 1;
                        q.push({r , c , steps + 1 , newMask});
                    }
                }
            }
        }

        return -1;
    }
};
