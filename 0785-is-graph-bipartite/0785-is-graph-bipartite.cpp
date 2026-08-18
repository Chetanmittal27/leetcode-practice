class Solution {
public:

    bool dfs(vector<vector<int>>& graph , int node , vector<int>& color , int curr){

        color[node] = curr;

        for(auto v : graph[node]){

            if(color[v] == -1){
                if(!dfs(graph , v , color , 1 - color[node])){
                    return false;
                }
            }

            else{
                if(color[v] == curr){
                    return false;
                }
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();

        vector<int>color(n , -1);

        for(int i = 0; i < n; i++){

            if(color[i] == -1){
                if(!dfs(graph , i , color , 0)){
                    return false;
                }
            }
        }

        return true;
    }
};