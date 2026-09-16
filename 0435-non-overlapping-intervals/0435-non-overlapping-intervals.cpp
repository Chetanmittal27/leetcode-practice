class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        if(n == 1) return 0;

        sort(intervals.begin() , intervals.end() , [](const vector<int>& a , const vector<int>& b){

            return a[1] < b[1];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];

        int ans = 0;

        for(int i = 1; i < n; i++){

            int first = intervals[i][0];
            int second = intervals[i][1];

            if(first < end){
                ans++;
            }

            else{
                start = first;
                end = second;
            }
        }

        return ans;
    }
};