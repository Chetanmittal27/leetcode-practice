class Solution {
public:
    bool isPalindrome(string s) {
        
        string str = "";

        for(auto ch : s){

            if(isalnum(ch)){
                str.push_back((char)tolower((unsigned char)ch));
            }
        }

        int n = str.length();

        int left = 0 , right = n - 1;

        while(left < right){

            if(str[left] != str[right]){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};