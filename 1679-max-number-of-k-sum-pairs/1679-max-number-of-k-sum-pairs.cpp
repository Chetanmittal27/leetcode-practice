class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();

        unordered_map<int , int>mpp;

        int count = 0;

        for(int i = 0; i < n; i++){

            int remaining = k - nums[i];

            if(mpp.find(remaining) != mpp.end()){
                count++;
                mpp[remaining]--;
                if(mpp[remaining] == 0){
                    mpp.erase(remaining);
                }
            }

            else{
                mpp[nums[i]]++;
            }
        }

        return count;
    }
};