class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        
        vector<int>temp(101 , 0);

        int n = bulbs.size();

        for(int i = 0; i < n; i++){

            temp[bulbs[i]] = temp[bulbs[i]] ^ 1;
        }

        vector<int>ans;

        for(int i = 1; i < 101; i++){
            if(temp[i] == 1){
                ans.push_back(i);
            }
        }

        return ans;
    }
};