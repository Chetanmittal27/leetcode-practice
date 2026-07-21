class Solution {
public:

    void powerSet(vector<int>& nums , int n , int i , set<vector<int>>& st , vector<int>& temp){

        if(i == n){
            st.insert(temp);
            return;
        }

        // include
        temp.push_back(nums[i]);
        powerSet(nums , n , i + 1 , st , temp);
        temp.pop_back();

        // exclude
        powerSet(nums , n , i + 1 , st , temp);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>>ans;

        set<vector<int>>st;

        vector<int>temp;

        sort(nums.begin() , nums.end()); 

        powerSet(nums , n , 0 , st , temp);

        for(auto it : st){
            ans.push_back(it);
        }

        return ans;
    }
};