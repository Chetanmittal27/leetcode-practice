class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }


        queue<tuple<int,int,int>>q;
        q.push({0 , -1 , 1});

        int mini = INT_MAX;
        
        vector<int>vis(n+1 , 0);

        while(!q.empty()){

            auto [wt , u , v] = q.front();
            q.pop();

            if(u != -1){
                mini = min(mini , wt);
            }

            vis[v] = 1;

            for(auto it : adj[v]){
                int adjCity = it.first;
                int adjWt = it.second;

                if(!vis[adjCity]){
                    q.push({adjWt , v , adjCity});
                }
            }
        }

        return mini;
    }
};