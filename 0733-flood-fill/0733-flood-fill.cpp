class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        vector<vector<int>>ans = image;

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>vis(m , vector<int>(n , 0));
        vis[sr][sc] = 1;

        queue<pair<int , int>>q;
        q.push({sr , sc});

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        while(!q.empty()){

            int len = q.size();

            for(int i = 0; i < len; i++){

                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                ans[row][col] = color;

                for(int j = 0; j < 4; j++){

                    int r = row + dx[j];
                    int c = col + dy[j];

                    if((r >= 0 && r < m) && (c >= 0 && c < n) && image[r][c] == image[row][col]){

                        if(!vis[r][c]){

                            vis[r][c] = 1;
                            q.push({r , c});
                        }
                    }
                }
            }
        }

        return ans;
    }
};