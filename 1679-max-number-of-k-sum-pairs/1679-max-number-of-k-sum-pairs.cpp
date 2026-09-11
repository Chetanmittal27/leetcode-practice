class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        int n = nums.size();

        sort(nums.begin() , nums.end());

        int ans = 0;

        int l = 0 , r = n-1;

        while(l < r){
            int sum = nums[l] + nums[r];

            if(sum == k){
                ans++;
                l++;
                r--;
            }

            else if(sum > k){
                r--;
            }

            else{
                l++;
            }
        }

        return ans;
    }
};