class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();

        int sum = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1){
                sum = sum + nums[i];
            }

            else{
                break;
            }
        }

        unordered_set<int>st;
        int maxi = *max_element(nums.begin() , nums.end());

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }
        
        int num = sum;
        while(num <= maxi){
            if(st.find(num) == st.end()){
                return num;
            }
            num++;
        }

        return num;
    }
};