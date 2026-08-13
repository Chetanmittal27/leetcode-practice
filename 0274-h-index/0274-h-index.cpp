class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();

        sort(citations.begin() , citations.end());
        int papers = 0;

        for(int i = n-1; i >= 0; i--){
            int count = n - i;

            if(citations[i] >= count){
                papers++;
            }

            else{
                return papers;
            }
        }

        return papers;
    }
};