class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int count0 = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == 0){
                count0++;
            }
        }

        if(count0 == n) return 0;
        if(count0 == 0) return n-1;

        vector<int>prefixOnes(n , 0);
        if(nums[0] == 0) prefixOnes[0] = 0;
        else{
            prefixOnes[0] = 1;
        }

        for(int i = 1; i < n; i++){

            if(nums[i] == 0){
                prefixOnes[i] = 0;
            }

            else{
                prefixOnes[i] = prefixOnes[i-1] + 1;
            }
        }


        vector<int>suffixOnes(n , 0);

        if(nums[n-1] == 0) suffixOnes[n-1] = 0;
        else{
            suffixOnes[n-1] = 1;
        }

        for(int i = n-2; i >= 0; i--){

            if(nums[i] == 0){
                suffixOnes[i] = 0;
            }

            else{
                suffixOnes[i] = suffixOnes[i+1] + 1;
            }
        }

        
        int ans = 0;

        for(int i = 0; i < n; i++){

            int total = 0;

            if(i > 0){
                total = total + prefixOnes[i-1];
            }

            if(i < n-1){
                total = total + suffixOnes[i+1];
            }

            ans = max(ans , total);
        }

        return ans;
    }
};