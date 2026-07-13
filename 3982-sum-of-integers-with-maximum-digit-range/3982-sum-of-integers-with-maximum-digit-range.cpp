class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        
        int n = nums.size();

        int maxi = INT_MIN;

        unordered_map<int , long long>mpp;

        for(int i = 0; i < n; i++){

            int number = nums[i];
            int small = (number % 10);
            int large = (number % 10);
            number = number / 10;

            while(number > 0){
                int val = (number % 10);
                
                small = min(small , val);
                large = max(large , val);

                number = number / 10;
            }

            mpp[large - small] = mpp[large - small] + nums[i];
            maxi = max(maxi , large - small);

        }

        return mpp[maxi];
    }
};