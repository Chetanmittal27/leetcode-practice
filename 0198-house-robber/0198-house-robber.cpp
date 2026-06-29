class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        int prev2 = nums[0];

        if(n == 1) return prev2;
        
        int prev1;

        if(n > 1){
            prev1 = max(nums[1] , prev2);
        }

        for(int i = 2; i < n; i++){

            int include = nums[i] + prev2;
            int exclude = 0 + prev1;

            int cal = max(include , exclude);

            prev2 = prev1;
            prev1 = cal;
        }

        return prev1;
    }
};