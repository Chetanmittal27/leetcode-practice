class Solution {
public:

    string binaryStr(int num){

        string ans = "";

        while(num > 0){
            int val = (num % 2);
            ans = to_string(val) + ans;
            num = num / 2;
        }

        if(ans.length() < 8){
            int n = 8 - ans.length();
            for(int i = 0; i < n; i++){
                ans = '0' + ans;
            }
        }

        return ans;
    }


    bool isPalindromic(string s) {
        
        int n = s.length();

        string str = "";

        for(int i = 0; i < n; i++){

            str = str + binaryStr((int)s[i]);
        }

        cout << str << endl;

        int len = str.length();

        int left = 0 , right = len - 1;

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