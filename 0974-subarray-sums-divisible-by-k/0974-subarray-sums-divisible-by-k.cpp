class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int n = nums.size();

        int count = 0;

        unordered_map<int,int>mpp;
        mpp[0] = 1;

        int prefixSum = 0;

        for(int i = 0; i < n; i++){

            prefixSum = prefixSum + nums[i];

            int rem = ((prefixSum % k) + k) % k;

            if(mpp.find(rem) != mpp.end()){

                count = count + mpp[rem];
            }

            mpp[rem]++;
        }


        return count;
    }
};