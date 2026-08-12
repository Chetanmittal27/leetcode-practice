class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int>arr(n , 0);
        set<pair<int,int>>st;

        for(auto edge : roads){
            int u = edge[0];
            int v = edge[1];

            st.insert({u , v});
            arr[u]++;
            arr[v]++;
        }

        int maxi = 0;

        for(int i = 0; i < n; i++){
            
            for(int j = i + 1; j < n; j++){

                int val = arr[i] + arr[j];

                if((st.find({i , j}) != st.end()) || (st.find({j , i}) != st.end())){
                    val = val - 1;
                }

                maxi = max(maxi , val);
            }
        }

        return maxi;
    }
};