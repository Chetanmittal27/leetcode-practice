class Solution {
public:
    bool isAnagram(string s, string t) {
        
        vector<int>temp(26 , 0);

        for(auto ch : s){
            temp[ch - 'a']++;
        }

        for(auto ch : t){
            temp[ch - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(temp[i] != 0) return false;
        }

        return true;
    }
};