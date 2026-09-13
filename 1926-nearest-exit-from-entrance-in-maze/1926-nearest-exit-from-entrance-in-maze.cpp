class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size();
        int n = maze[0].size();
        
        queue<tuple<int,int,int>>q;
        int start = entrance[0];
        int end = entrance[1];

        q.push({start , end , 0});

        vector<vector<int>>vis(m , vector<int>(n , 0));
        vis[start][end] = 1;

        int dx[4] = {0 , -1 , 0 , +1};
        int dy[4] = {-1 , 0 , +1 , 0};

        while(!q.empty()){

            auto [row , col , steps] = q.front();
            q.pop();

            if(row != start || col != end){

                if((row == 0 || row == m-1) || (col == 0 || col == n-1)){
                    return steps;
                }
            }


            for(int i = 0; i < 4; i++){

                int r = row + dx[i];
                int c = col + dy[i];

                if((r >= 0 && r < m) && (c >= 0 && c < n) && maze[r][c] == '.'){

                    if(!vis[r][c]){
                        vis[r][c] = 1;
                        q.push({r , c , steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};