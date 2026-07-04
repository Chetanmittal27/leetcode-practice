class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        int n = arr.size();
        int q = queries.size();

        vector<int>temp(n+1 , 0);

        for(int i = 0; i < n; i++){
            temp[i+1] = temp[i] ^ arr[i];
        }


        vector<int>ans;

        for(auto query : queries){
            int left = query[0];
            int right = query[1];

            int cal = temp[right+1] ^ temp[left];

            ans.push_back(cal);
        }

        return ans;
    }
};