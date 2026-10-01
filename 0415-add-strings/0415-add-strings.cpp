class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int m = num1.length();
        int n = num2.length();

        int extra = 0;

        int i = m - 1 , j = n - 1;

        string str = "";

        while(i >= 0 || j >= 0 || extra > 0){

            int sum = extra;

            if(i >= 0){
                sum = sum + (num1[i] - '0');
                i--;
            }

            if(j >= 0){
                sum = sum + (num2[j] - '0');
                j--;
            }

            str = to_string(sum % 10) + str;

            extra = sum / 10;
        }

        return str;
    }
};