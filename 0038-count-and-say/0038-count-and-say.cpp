class Solution {
public:
    string countAndSay(int n) {
        
        string str = "1";

        if(n == 1) return str;

        for(int i = 2; i <= n; i++){

            string temp = "";

            int l = 0 , r = 0;

            while(r < str.length()){

                while(r < str.length() && str[r] == str[l]){
                    r++;
                }

                temp = temp + to_string(r - l) + str[l];
                l = r;
            }

            if(l < str.length()){
                temp = temp + to_string(r - l) + str[l];
            }

            str = temp;
        }

        return str;
    }
};