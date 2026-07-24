class Solution {
public:
    
    int solve(vector<int>& nums , int n , int sum , int target){

        if(n < 0){
            if(sum == target){
                return 1;
            }

            return 0;
        }

        // include + 
        int add = solve(nums , n - 1 , sum + nums[n] , target);

        // include -
        int subtract = solve(nums , n - 1 , sum - nums[n] , target);

        return add + subtract;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        return solve(nums , n-1 , 0 , target);
    }
};