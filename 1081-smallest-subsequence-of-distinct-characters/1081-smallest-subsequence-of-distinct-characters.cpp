class Solution {
public:

    string smallestSubsequence(string s) {
        
        int n = s.length();

        vector<int>lastIdx(26 , -1);

        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        string str = "";
        vector<bool>included(26 , false);

        for(int i = 0; i < n; i++){

            if(included[s[i] - 'a']){
                continue;
            }


            while(!str.empty()  &&  str.back() > s[i]  &&  lastIdx[str.back() - 'a'] > i){

                included[str.back() - 'a'] = false;
                str.pop_back();
            }

            str.push_back(s[i]);
            included[s[i] - 'a'] = true;
        }

        return str;
    }
};