class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<vector<pair<int,char>>>adj(n);

        for(auto edge : redEdges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v , 'r'});
        }


        for(auto edge : blueEdges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v , 'b'});
        }


        queue<tuple<int , int , char>>q;
        q.push({0 , 0 , 'r'});
        q.push({0 , 0 , 'b'});

        vector<vector<int>>distance(n , vector<int>(2 , INT_MAX));
        distance[0][0] = 0;
        distance[0][1] = 0;

        while(!q.empty()){

            auto [wt , node , color] = q.front();
            q.pop();

            for(auto &it : adj[node]){
                int adjVer = it.first;
                char adjColor = it.second;

                if(adjColor != color){
                    int calDistance = wt + 1;

                    if(calDistance < distance[adjVer][adjColor == 'r' ? 0 : 1]){
                        distance[adjVer][adjColor == 'r' ? 0 : 1] = calDistance;
                        q.push({calDistance , adjVer , adjColor});
                    }
                }
            }
        }

        
        vector<int>answer(n);

        for(int i = 0; i < n; i++){
            int mini = min(distance[i][0] , distance[i][1]);
            answer[i] = (mini == INT_MAX ? -1 : mini);
        }

        return answer;
    }
};