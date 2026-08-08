class Solution {
public:

    void dfs(vector<vector<int>>& heights , int row , int col , vector<vector<int>>& vis){
        vis[row][col] = 1;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < 4; i++){

            int r = row + dx[i];
            int c = col + dy[i];

            if((r >= 0 && r < heights.size()) && (c >= 0 && c < heights[0].size()) && (heights[r][c] >= heights[row][col])){

                if(!vis[r][c]){
                    dfs(heights , r , c , vis);
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>ans;
        
        vector<vector<int>>pacific(m , vector<int>(n , 0));

        for(int j = 0; j < n; j++){
            dfs(heights , 0 , j , pacific);
        }

        for(int i = 0; i < m; i++){
            dfs(heights , i , 0 , pacific);
        }

        vector<vector<int>>atlantic(m , vector<int>(n , 0));

        for(int j = 0; j < n; j++){
            dfs(heights , m-1 , j , atlantic);
        }

        for(int i = 0; i < m; i++){
            dfs(heights , i , n-1 , atlantic);
        }


        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i , j});
                }
            }
        }

        return ans;
    }
};