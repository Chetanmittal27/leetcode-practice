class Solution {
public:

    void dfs(vector<vector<int>>& adj , vector<int>& vis , int node){

        vis[node] = 1;

        for(auto v : adj[node]){
            if(!vis[v]){
                dfs(adj , vis , v);
            }
        }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        vector<vector<int>>adj(n);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < n; j++){

                if(i != j && isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int>vis(n , 0);
        int count = 0;

        for(int i = 0; i < n; i++){

            if(!vis[i]){
                count++;
                dfs(adj , vis , i);
            }
        }

        return count;
    }
};