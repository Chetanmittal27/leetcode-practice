class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int>hash(26 , 0);

        for(auto ch : t){
            hash[ch - 'a']++;
        }

        for(auto ch : s){
            hash[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(hash[i] != 0){
                return char('a' + i);
            }
        }
        return '-1';
    }
};