class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();

        int count0 = 0;

        unordered_set<int>st;

        for(int i = 0; i < n; i++){

            if(nums[i] == 0){
                count0++;
                st.insert(i);
            }
        }

        if(count0 == n) return 0;
        if(count0 == 0) return n - 1;

        int ans = 0;

        for(auto it : st){

            int count = 0;

            for(int j = 0; j < n; j++){

                if(j == it) continue;

                if(nums[j] == 1){
                    count++;
                }

                else{
                    ans = max(ans , count);
                    count = 0;
                }
            }

            if(count > 0){
                ans = max(ans , count);
            }
        }

        return ans;

    }
};