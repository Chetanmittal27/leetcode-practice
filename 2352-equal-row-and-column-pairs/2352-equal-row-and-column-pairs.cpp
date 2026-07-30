class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();

        int count = 0;

        vector<vector<int>>gridColumns(n);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                gridColumns[j].push_back(grid[i][j]);
            }
        }

        for(auto row : grid){

            for(auto col : gridColumns){

                if(row == col){
                    count++;
                }
            }
        }

        return count;
    }
};