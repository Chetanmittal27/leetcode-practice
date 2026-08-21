class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>ans;

        priority_queue<pair<int , pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>minHeap;

        set<pair<int,int>>st;

        minHeap.push({nums1[0] + nums2[0] , {0 , 0}});
        st.insert({0 , 0});

        while(!minHeap.empty() && k > 0){

            auto it = minHeap.top();
            int sum = it.first;
            int i = it.second.first;
            int j = it.second.second;
            minHeap.pop();

            ans.push_back({nums1[i] , nums2[j]});

            if(i+1 < nums1.size() && st.find({i+1 , j}) == st.end()){
                minHeap.push({nums1[i+1] + nums2[j] , {i+1 , j}});
                st.insert({i+1 , j});
            }

            if(j+1 < nums2.size() && st.find({i , j + 1}) == st.end()){
                minHeap.push({nums1[i] + nums2[j+1] , {i , j+1}});
                st.insert({i , j+1});
            }

            k--;
        }

        return ans;
    }
};