class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        
        int n = nums.size();

        sort(nums.begin() , nums.end());

        long long totalSum = 0;

        for(int i = n-1; i >= n-k; i--){

            long long calMul = (long long)nums[i] * (long long)mul;

            if(calMul > nums[i]){
                totalSum = totalSum + calMul;
                mul--;
            }

            else{
                totalSum = totalSum + (long long)nums[i];
            }
        }

        return totalSum;
    }
};