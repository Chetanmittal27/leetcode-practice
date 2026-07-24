class Solution {
public:
    
    int solve(vector<int>& nums , int n , int sum , int i , int target , vector<vector<int>>& dp , int total){

        if(i == n){
            if(sum == target){
                return 1;
            }

            return 0;
        }

        if(dp[i][sum + total] != -1){
            return dp[i][sum + total];
        }

        // include + 
        int add = solve(nums , n  , sum + nums[i] , i + 1 , target , dp , total);

        // include -
        int subtract = solve(nums , n , sum - nums[i] , i + 1 , target , dp , total);

        dp[i][sum + total] = add + subtract;

        return dp[i][sum + total];
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int total = accumulate(nums.begin() , nums.end() , 0);
        
        vector<vector<int>>dp(n , vector<int>(2 * total + 1 , -1));

        return solve(nums , n , 0 , 0 , target , dp , total);
    }
};