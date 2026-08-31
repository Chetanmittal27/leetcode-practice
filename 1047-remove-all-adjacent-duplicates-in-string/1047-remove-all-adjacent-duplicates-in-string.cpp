class Solution {
public:
    string removeDuplicates(string s) {
        
        if(s.length() == 1) return s;

        int i = 1;

        while(i < s.length()){
            if(s[i] == s[i-1]){
                s.erase(i-1 , 2);
                if(i > 1) i--;
                else{
                    i = 1;
                }
            }

            else{
                i++;
            }
        }

        return s;
    }
};