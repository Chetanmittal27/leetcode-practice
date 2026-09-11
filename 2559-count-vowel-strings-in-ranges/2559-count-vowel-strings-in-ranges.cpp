class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();

        vector<int>countValid(n , 0);

        string str = words[0];
        if((string("aeiou").find(str[0]) != string::npos) && (string("aeiou").find(str.back()) != string::npos)){

            countValid[0] = 1;
        }

        for(int i = 1; i < n; i++){
            string str = words[i];

            if((string("aeiou").find(str[0]) != string::npos) && (string("aeiou").find(str.back()) != string::npos)){

                countValid[i] = countValid[i-1] + 1;
            }

            else{
                countValid[i] = countValid[i-1];
            }
        }

        int m = queries.size();

        vector<int>answer(m , -1);

        for(int i = 0; i < m; i++){

            int start = queries[i][0];
            int end = queries[i][1];

            answer[i] = countValid[end];

            if(start > 0){
                answer[i] = answer[i] - countValid[start - 1];
            }
        }

        return answer;
    }
};