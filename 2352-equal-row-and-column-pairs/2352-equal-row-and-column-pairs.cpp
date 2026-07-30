class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int count = 0;

        map<vector<int> , int>mpp;

        for(auto row : grid){
            mpp[row]++;;
        }

        for(int i = 0; i < n; i++){

            vector<int>temp;

            for(int j = 0; j < n; j++){
                
                temp.push_back(grid[j][i]);
            }

            if(mpp.find(temp) != mpp.end()){
                count = count + mpp[temp];
            }
        }


        return count;
    }
};