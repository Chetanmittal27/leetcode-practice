class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());

        int n = nums.size();

        set<vector<int>>st;

        for(int i = 0; i < n-3; i++){

            for(int j = i+1; j < n-2; j++){

                int left = j+1 , right = n-1;

                long long x = (long long)target - (long long)nums[i] - (long long)nums[j];

                while(left < right){

                    long long sum = (long long)nums[left] + (long long)nums[right];

                    if(sum == x){

                        st.insert({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;
                    }

                    else if(sum > x){
                        right--;
                    }

                    else{
                        left++;
                    }
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