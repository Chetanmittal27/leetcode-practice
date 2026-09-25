class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        

        int n = nums.size();

        sort(nums.begin() , nums.end());

        set<vector<int>>st;

        for(int i = 0; i < n; i++){

            long long target = 0 - (long long)nums[i];

            int left = i+1 , right = n-1;

            while(left < right){

                long long sum = (long long)nums[left] + (long long)nums[right];

                if(sum == target){

                    st.insert({nums[i] , nums[left] , nums[right]});
                    left++;
                    right--;
                }

                else if(sum > target){
                    right--;
                }

                else{
                    left++;
                }
            }
        }


        vector<vector<int>>ans;

        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};