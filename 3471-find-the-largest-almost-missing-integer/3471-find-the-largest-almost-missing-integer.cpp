class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        int n = nums.size();

        if(k == n) return *max_element(nums.begin() , nums.end());

        int l = 0 , r = k-1;

        unordered_map<int,int>mpp;

        while(r < n){

            for(int i = l; i <= r; i++){

                mpp[nums[i]]++;
            }

            l++;
            r++;
        }

        int ans = -1;

        for(auto it : mpp){
            if(it.second == 1){
                ans = max(ans , it.first);
            }
        }

        return ans;
    }
};