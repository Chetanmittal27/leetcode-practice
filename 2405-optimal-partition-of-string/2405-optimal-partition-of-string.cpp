class Solution {
public:
    int partitionString(string s) {
        
        int n = s.length();

        int r = 0;
        int mini = 0;

        unordered_set<char>st;

        while(r < n){

            if(st.find(s[r]) != st.end()){
                mini++;
                st.clear();
            }

            st.insert(s[r]);
            r++;
        }

        if(!st.empty()){
            mini++;
        }

        return mini;
    }
};