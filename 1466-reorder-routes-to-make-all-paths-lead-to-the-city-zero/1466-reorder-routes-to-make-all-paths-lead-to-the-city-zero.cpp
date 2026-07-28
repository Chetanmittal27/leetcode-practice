class Solution {
public:
    
    void dfs(vector<vector<int>>& connections , vector<vector<pair<int,int>>>& adj , vector<int>& vis , int node , int &count){

        vis[node] = 1;

        for(auto it : adj[node]){
            int v = it.first;
            int type = it.second;

            if(!vis[v]){
                count = count + type;
                dfs(connections , adj , vis , v , count);
            }
        }
    }


    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<vector<pair<int,int>>>adj(n);

        for(auto &edge : connections){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v , 1});
            adj[v].push_back({u , 0});
        }


        vector<int>vis(n , 0);
        int count = 0;

        dfs(connections , adj , vis , 0 , count);

        return count;
    }
};