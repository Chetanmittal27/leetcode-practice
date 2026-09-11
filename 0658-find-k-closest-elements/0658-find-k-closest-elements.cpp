class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>minHeap;

        for(int i = 0; i < n; i++){

            minHeap.push({abs(arr[i] - x) , arr[i]});
        }

        vector<int>ans;

        while(k > 0){
            auto p = minHeap.top();
            minHeap.pop();

            ans.push_back(p.second);
            k--;
        }

        sort(ans.begin() , ans.end());
        return ans;
    }
};