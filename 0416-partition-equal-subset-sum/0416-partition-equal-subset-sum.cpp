class Solution {
public:

    bool checkPartition(vector<int>& nums , int n , int i , int sum , int target , vector<vector<int>>& dp){

        if(i == n){
            if(sum == target){
                return true;
            }

            return false;
        }

        if(dp[i][sum] != -1){
            return dp[i][sum];
        }

        bool include = checkPartition(nums , n , i + 1 , sum + nums[i] , target , dp);

        bool exclude = checkPartition(nums , n , i + 1 , sum , target , dp);

        dp[i][sum] = (include || exclude);

        return dp[i][sum];
    }


    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();

        unordered_set<int>st;

        int total = accumulate(nums.begin() , nums.end() , 0);

        if(total % 2 != 0) return false;

        vector<vector<int>>dp(n , vector<int>(1e5 + 1 , -1));

        return checkPartition(nums , n , 0 , 0 , total / 2 , dp);
    }
};