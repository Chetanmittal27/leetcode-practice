class Solution {
public:

    void dfs(vector<vector<int>>& graph , vector<vector<int>>& ans , vector<int>& temp , int node){

        temp.push_back(node);

        if(node == graph.size() - 1){
            ans.push_back(temp);
        }

        for(auto v : graph[node]){

            dfs(graph , ans , temp , v);
        }

        temp.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>ans;
        
        vector<int>temp;

        dfs(graph , ans , temp , 0);

        return ans;
    }
};