class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n = nums.size();

        int count = 0;

        int l = 0 , r = 0;
        long long cal = 1;

        while(r < n){

            cal = cal * (long long)nums[r];

            while(cal >= k){
                cal = cal / nums[l];
                l++;
            }

            count = count + (r - l + 1);
            r++;
        }

        return count;
    }
};