class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int count = 0 , x = -1;

        for(int i = 0; i < n; i++){

            if(count == 0){
                x = nums[i];
                count = 1;
            }

            else if(nums[i] == x){
                count++;
            }

            else{
                count--;
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == x){

                cnt++;
            }
        }

        if(cnt > n/2) return x;
        return -1;
    }
};