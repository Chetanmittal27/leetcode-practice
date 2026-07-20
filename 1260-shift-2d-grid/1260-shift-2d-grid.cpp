class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>temp(m , vector<int>(n));

        while(k > 0){

            for(int i = m-1; i >= 0; i--){

                for(int j = n-1; j >= 0; j--){

                    if(j == n-1){
                        int row = (i + 1) % m;
                        int col = (j + 1) % n;

                        temp[row][col] = grid[i][j];
                    }

                    else{
                        temp[i][j+1] = grid[i][j];
                    }
                }
            }

            grid = temp;

            k--;
        }

        return grid;
    }
};