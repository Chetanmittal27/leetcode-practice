// class Solution {
// public:
//     int minScore(int n, vector<vector<int>>& roads) {
        
//         vector<vector<pair<int,int>>>adj(n+1);

//         for(auto road : roads){
//             int u = road[0];
//             int v = road[1];
//             int w = road[2];

//             adj[u].push_back({v , w});
//             adj[v].push_back({u , w});
//         }


//         priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>>q;

//         q.push({0 , -1 , 1});

//         int mini = INT_MAX;
        
//         vector<int>vis(n+1 , 0);

//         while(!q.empty()){

//             auto [wt , u , v] = q.top();
//             q.pop();

//             if(vis[v]) continue;

//             vis[v] = 1;

//             if(u != -1){
//                 mini = min(mini , wt);
//             }

//             for(auto it : adj[v]){
//                 int adjCity = it.first;
//                 int adjWt = it.second;

//                 if(!vis[adjCity]){
//                     q.push({adjWt , v , adjCity});
//                 }
//             }
//         }

//         return mini;
//     }
// };



class Solution {
public:

    void dfs(vector<vector<pair<int,int>>>& adj , vector<int>& vis , int node , int& mini){
        
        vis[node] = 1;

        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;

            mini = min(mini , wt);

            if(!vis[v]){
                dfs(adj , vis , v , mini);
            }
        }
    }


    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }


        vector<int>vis(n+1 , 0);

        int mini = INT_MAX;

        dfs(adj , vis , 1 , mini);

        return mini;
    }
};