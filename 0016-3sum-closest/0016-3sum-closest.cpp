class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();

        int mini = INT_MIN , maxi = INT_MAX;

        sort(nums.begin() , nums.end());

        for(int i = 0; i < n-2; i++){

            int l = i + 1 , r = n - 1;

            while(l < r){

                int sum = nums[i] + nums[l] + nums[r];

                if(sum == target){
                    return target;
                }

                else if(sum < target){
                    if (mini == INT_MIN || target - sum < target - mini) {
                        mini = sum;
                    }
                    l++;
                }

                else{
                    if(maxi == INT_MAX || sum - target < maxi - target){
                        maxi = sum;
                    }

                    r--;
                }
            }
        }

        long long val1 = (long long)maxi - (long long)target;
        long long val2 = (long long)target - (long long)mini;

        if(val1 < val2) return maxi;
        return mini;
    }
};