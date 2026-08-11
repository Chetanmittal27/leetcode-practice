class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<pair<int,int>>temp;

        for(int i = 0; i < n; i++){
            temp.push_back({nums[i] , i});
        }

        sort(temp.begin() , temp.end());

        int left = 0 , right = n - 1;

        while(left < right){

            int a = temp[left].first;
            int b = temp[right].first;

            if((a + b) == target){
                return {temp[left].second , temp[right].second};
            }

            else if((a + b) < target){
                left++;
            }

            else{
                right--;
            }
        }

        return {-1};
    }
};