class Solution {
public:
    string removeStars(string s) {
        
        int n = s.length();

        stack<char>st;

        for(auto ch : s){
            
            if(ch != '*'){
                st.push(ch);
            }

            else{
                st.pop();
            }
        }

        int m = st.size();
        for(int i = m-1; i >= 0; i--){
            s[i] = st.top();
            st.pop();
        }

        return s.substr(0 , m);
    }
};