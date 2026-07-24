class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int>mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }

        int k = 0;

        for(auto it : mpp){
            int val = it.first;
            int count = it.second;

            for(int i = 0; i < (count <= 2 ? count : 2); i++){

                nums[k] = val;
                k++;
            }
        }

        return k;
    }
};