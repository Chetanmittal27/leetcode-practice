class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>minHeap;

        int children = g.size();
        int cookies = s.size();

        for(int i = 0; i < children; i++){
            minHeap.push({g[i] , i});
        }

        sort(s.begin() , s.end());

        int i = 0;
        int count = 0;

        while(!minHeap.empty() && i < cookies){

            auto p = minHeap.top();
            minHeap.pop();

            int greed = p.first;
            int child = p.second;

            while(i < cookies){
                if(s[i] >= greed){
                    count++;
                    i++;
                    break;
                }
                
                i++;
            }
        }

        return count;
    }
};