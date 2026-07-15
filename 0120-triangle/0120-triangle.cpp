class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {
         
        int n = triangle.size();

        vector<vector<int>>dp(n , vector<int>(n , INT_MAX));

        for(int i = 0; i < n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2; i >= 0; i--){

            for(int j = n-2; j >= 0; j--){

                int same = dp[i+1][j];
                int prev = dp[i+1][j+1];
                
                if(j > triangle[i].size() - 1){
                    continue;
                }

                dp[i][j] = triangle[i][j] + min(same , prev);
            }
        }

        return dp[0][0];
    }
};