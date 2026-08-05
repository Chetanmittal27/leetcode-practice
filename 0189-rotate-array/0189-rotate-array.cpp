class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();

        int val = k % n;

        reverse(nums.begin() , nums.begin() + (n - val));
        reverse(nums.begin() + (n - val) , nums.end());
        reverse(nums.begin() , nums.end());
    }
};