class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();

        int l = 0 , r = 0;

        while(r < n){

            if(nums[r] != nums[l]){
                nums[++l] = nums[r];
            }

            r++;
        }

        return l + 1;
    }
};