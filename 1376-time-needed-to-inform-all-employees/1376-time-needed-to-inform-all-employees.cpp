class Solution {
public:

    void dfs(int emp , vector<int>& manager , vector<int>& informTime , vector<vector<int>>& adj , int &timeTaken , int calTime){

        calTime = calTime + informTime[emp];
        timeTaken = max(timeTaken , calTime);

        for(auto it : adj[emp]){
            dfs(it , manager ,informTime , adj , timeTaken ,calTime);
        }

    }


    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>>adj(n);

        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                adj[manager[i]].push_back(i);
            }
        }

        int timeTaken = 0;

        dfs(headID , manager , informTime , adj , timeTaken , 0);

        return timeTaken;
    }
};