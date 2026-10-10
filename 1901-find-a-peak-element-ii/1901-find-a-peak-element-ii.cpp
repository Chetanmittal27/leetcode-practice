class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                bool isCheck = true;

                for(int k = 0; k < 4; k++){

                    int  r = i + dx[k];
                    int c = j + dy[k];

                    if((r >= 0 && r < n) && (c >= 0 && c < m)){

                        if(mat[r][c] >= mat[i][j]){
                            isCheck = false;
                            break;
                        }
                    }
                }

                if(isCheck == true){
                    return {i , j};
                }
            }
        }

        return {-1};
    }
};