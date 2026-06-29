class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<vector<int>>adj(n+1);

        for(auto arr : trust){
            int u = arr[0];
            int v = arr[1];

            adj[v].push_back(u);
        }

        int judge = -1;

        for(int i = 1; i <= n; i++){
            if(adj[i].size() == n-1){
                judge = i;
            }
        }

        if(judge == -1) return -1;

        for(auto arr : trust){
            int u = arr[0];
            int v = arr[1];

            if(u == judge){
                return -1;
            }
        }

        return judge;
    }
};