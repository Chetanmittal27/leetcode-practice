class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.length();

        int left = 0 , right = n - 1;

        while(left < right){

            while(left < right && string("aeiou").find(tolower(s[left])) == string::npos){
                left++;
            }

            while(left < right && string("aeiou").find(tolower(s[right])) == string::npos){
                right--;
            }

            swap(s[left] , s[right]);
            left++;
            right--;
        }

        return s;
    }
};