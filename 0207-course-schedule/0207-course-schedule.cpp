class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);

        vector<int>inDegree(numCourses , 0);
        for(auto &edge : prerequisites){

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int>q;

        for(int i = 0; i < numCourses; i++){

            if(inDegree[i] == 0){
                q.push(i);
            }
        }


        vector<int>ans;

        while(!q.empty()){

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto v : adj[node]){

                inDegree[v]--;

                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        if(ans.size() == numCourses) return true;
        return false;
    }
};