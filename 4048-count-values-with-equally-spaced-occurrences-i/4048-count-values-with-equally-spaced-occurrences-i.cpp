class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int , vector<int>>mpp;

        for(int i = 0; i < n; i++){

            mpp[nums[i]].push_back(i);
        }

        int ans = 0;

        for(auto it : mpp){

            if(it.second.size() == 3){

                int i1 = it.second[0];
                int i2 = it.second[1];
                int i3 = it.second[2];

                if((i2 - i1) == (i3 - i2)){
                    ans++;
                }
            }
        }

        return ans;
    }
};