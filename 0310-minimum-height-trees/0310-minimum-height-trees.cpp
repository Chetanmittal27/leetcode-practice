class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};
        
        vector<vector<int>>adj(n);
        vector<int>inDegree(n , 0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            inDegree[u]++;
            inDegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        queue<int>q;

        for(int i = 0; i < n; i++){

            if(inDegree[i] == 1){
                q.push(i);
            }
        }


        while(n > 2){

            int len = q.size();
            n = n - len;

            for(int i = 0; i < len; i++){

                auto node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    inDegree[it]--;

                    if(inDegree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int>ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;

    }
};