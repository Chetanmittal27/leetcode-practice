class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>temp(n , -1);

        temp[n-1] = -1;

        for(int i = n-2; i >= 0; i--){

            temp[i] = max(nums[i+1] , temp[i+1]);
        }

        for(int i = 0; i < n-2; i++){

            for(int j = i+1; j < n-1; j++){

                if(nums[j] > nums[i]){

                    if(temp[j] > nums[j]){
                        return true;
                    }
                }

                else{
                    break;
                }
            }
        }

        return false;
    }
};