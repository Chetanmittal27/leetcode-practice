class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin() , potions.end());

        vector<int>ans;

        for(int i = 0; i < n; i++){

            int idx = -1;

            int l = 0 , r = m-1;

            while(l <= r){

                int mid = l + (r - l) / 2;

                long long product = (long long)spells[i] * (long long)potions[mid];

                if(product >= success){
                    idx = mid;
                    r = mid - 1;
                }

                else {
                    l = mid + 1;
                }
            }
            
            if(idx == -1){
                ans.push_back(0);
            }

            else{
                ans.push_back(m - idx);
            }
        }

        return ans;
    }
};