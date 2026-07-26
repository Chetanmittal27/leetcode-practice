class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 3) return (nums[0] * nums[1] * nums[2]);

        int maxi = INT_MIN;

        sort(nums.begin() , nums.end());

        int first = nums[n-1] * nums[n-2] * nums[n-3];
        int second = nums[0] * nums[1] * nums[n-1];

        maxi = max(maxi, max(first, second));

        return maxi;
    }
};