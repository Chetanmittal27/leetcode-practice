class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int large = nums[0];
        int secondLarge = -1;

        for(int i = 1; i < n; i++){

            if(nums[i] > large){
                secondLarge = large;
                large = nums[i];
            }

            else if(nums[i] <= large && nums[i] > secondLarge){
                secondLarge = nums[i];
            }
        }


        return (large - 1) * (secondLarge - 1);
    }
};