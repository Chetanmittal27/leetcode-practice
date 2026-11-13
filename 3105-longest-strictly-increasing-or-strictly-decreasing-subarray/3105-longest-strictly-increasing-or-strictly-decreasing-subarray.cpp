class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans = 0;

        int n = nums.size();
        if(n == 1) return 1;

        int inc = 1 , dec = 1;

        for(int i = 1; i < n; i++){

            if(nums[i] < nums[i-1]){
                inc = 1;
                dec++;
            }

            else if(nums[i] > nums[i-1]){
                dec = 1;
                inc++;
            }

            else{
                dec = 1;
                inc = 1;
            }

            ans = max(ans , max(inc , dec));
            
        }

        return ans;
    }
};