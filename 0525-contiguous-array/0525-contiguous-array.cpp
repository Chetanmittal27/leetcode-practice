class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();

        int maxi = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }


        unordered_map<int , int>mpp;
        mpp[0] = -1;

        int prefixSum = 0;

        for(int i = 0; i < n; i++){

            prefixSum = prefixSum + nums[i];

            int remaining = -prefixSum;

            if(mpp.find(remaining) != mpp.end()){
                maxi = max(maxi , i - mpp[remaining]);
            }

            else{
                mpp.insert({remaining , i});
            }
        }

        return maxi;
    }
};