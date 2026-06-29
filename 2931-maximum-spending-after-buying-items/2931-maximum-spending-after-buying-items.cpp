class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        
        vector<long long>arr;

        for(auto shop : values){

            for(auto item : shop){

                arr.push_back(item);
            }
        }

        sort(arr.begin() , arr.end());

        int day = 1;

        long long expenditure = 0;

        for(int i = 0; i < arr.size(); i++){
            expenditure = expenditure + (arr[i] * day);
            day++;
        }

        return expenditure;
    }
};