class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {

        int n = nums.size();

        int maxi = INT_MIN;

        vector<int>leftMaxi(n);
        leftMaxi[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--){
            leftMaxi[i] = max(nums[i] , leftMaxi[i+1]);
        }

        for(int i = 0; i < n; i++){
            if(i + k < n){
                maxi = max(maxi , nums[i] + leftMaxi[i+k]);
            }

            else{
                break;
            }
        }

        return maxi;
    }
};