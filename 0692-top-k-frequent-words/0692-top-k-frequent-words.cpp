class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string , int>mpp;

        for(auto str : words){
            mpp[str]++;
        }

        vector<pair<string , int>>arr(mpp.begin() , mpp.end());

        sort(arr.begin() , arr.end() , [](const pair<string , int>& p , const pair<string , int>& q){

            if(p.second == q.second){
                return p.first < q.first;
            }

            return p.second > q.second;
        });

        vector<string>ans;

        for(int i = 0; i < k; i++){
            ans.push_back(arr[i].first);
        }

        return ans;
    }
};