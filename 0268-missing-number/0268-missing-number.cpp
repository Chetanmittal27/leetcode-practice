class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            ans = ans ^ nums[i];
        }

        for(int num = 0; num <= nums.size(); num++){
            ans = ans ^ num;
        }

        return ans;
    }
};