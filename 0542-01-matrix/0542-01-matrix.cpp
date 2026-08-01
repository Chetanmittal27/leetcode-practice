class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>ans(m , vector<int>(n , 0));

        vector<vector<int>>vis(m , vector<int>(n , 0));

        queue<tuple<int,int,int>>q;
        
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i , j , 0});
                }
            }
        }

        int dx[4] = {0 , - 1, 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        while(!q.empty()){

            auto [row , col , steps] = q.front();
            q.pop();

            for(int i =  0; i < 4; i++){

                int r = row + dx[i];
                int c = col + dy[i];

                if((r >= 0 && r < m) && (c >= 0 && c < n) && mat[r][c] == 1){

                    if(!vis[r][c]){
                        ans[r][c] = steps + 1;
                        mat[r][c] = 0;
                        vis[r][c] = 1;
                        q.push({r , c , steps + 1});
                    }
                }
            }
        }

        return ans;
    }
};