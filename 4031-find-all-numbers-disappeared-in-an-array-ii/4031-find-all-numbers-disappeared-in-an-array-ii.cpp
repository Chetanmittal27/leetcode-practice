class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        
        vector<vector<int>>ans;

        int n = nums.size();

        unordered_set<int>s;

        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }


        int low = -1 , high = -1;

        while(lower <= upper){

            if(s.find(lower) == s.end()){
                if(low == -1){
                    low = lower;
                }

                high = lower;
            }

            else{
                if(low != -1 && high != -1){
                    ans.push_back({low , high});
                    low = -1 , high = -1;
                }
            }
            
            lower++;
        }

        if(low != -1 && high != -1){
            ans.push_back({low , high});
        }

        return ans;
    }
};