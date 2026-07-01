class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int,int>mpp;

        mpp[0] = -1;

        int prefixSum = 0;

        int count = 0;

        for(int i = 0; i < n; i++){

            prefixSum = prefixSum + nums[i];
            
            if((mpp.find(prefixSum % k) != mpp.end()) && (-mpp[prefixSum % k] + i) >= 2){
                count++;
            }

            else{
                mpp.insert({prefixSum % k , i});
            }
        }

        return count > 0 ? true : false;
    }
};