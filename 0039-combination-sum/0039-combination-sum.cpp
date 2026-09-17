class Solution {
public:

    void solve(vector<int>& candidates, int i , int sum , int target , set<vector<int>>& st , vector<int>& temp){

        if(sum == target){
            st.insert(temp);
            return;
        }

        if(sum > target || i >= candidates.size()){
            return;
        }


        // include
        temp.push_back(candidates[i]);
        solve(candidates, i , sum + candidates[i] , target , st , temp);
        temp.pop_back();

        // exclude
        solve(candidates , i+1 , sum , target , st , temp);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();

        set<vector<int>>st;

        vector<int>temp;

        solve(candidates , 0 , 0 , target , st , temp);

        vector<vector<int>>ans;

        for(auto v : st){
            ans.push_back(v);
        }

        return ans;
    }
};