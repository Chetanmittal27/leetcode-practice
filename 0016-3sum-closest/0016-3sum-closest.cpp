class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();

        int mini = INT_MIN , maxi = INT_MAX;

        for(int i = 0; i < n-2; i++){

            for(int j = i+1; j < n-1; j++){

                for(int k = j+1; k < n; k++){

                    int sum = nums[i] + nums[j] + nums[k];

                    if(sum == target){
                        return target;
                    }

                    else if(sum > target && sum < maxi){
                        maxi = sum;
                    }

                    else if(sum < target && sum > mini){
                        mini = sum;
                    }
                }
            }
        }

        long long val1 = (long long)maxi - (long long)target;
        long long val2 = (long long)target - (long long)mini;

        if(val1 < val2) return maxi;
        return mini;
    }
};