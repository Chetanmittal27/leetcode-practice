class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();

        int smallest = *min_element(nums.begin() , nums.end());
        int largest = *max_element(nums.begin() , nums.end());

        unordered_set<int>st;

        for(auto it : nums){
            st.insert(it);
        }

        vector<int>ans;

        for(int num = smallest; num <= largest; num++){
            if(st.find(num) == st.end()){
                ans.push_back(num);
            }
        }

        return ans;
    }
};