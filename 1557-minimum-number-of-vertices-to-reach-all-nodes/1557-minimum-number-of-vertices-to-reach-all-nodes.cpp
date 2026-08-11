class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        vector<int>inDegree(n , 0);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};