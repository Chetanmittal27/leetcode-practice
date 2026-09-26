class Solution {
public:

    void solve(int n , string& str , vector<string>& ans){

        if(str.length() > 1){

            int len = str.length();

            if(str[len-1] != '1' && str[len-2] != '1'){

                return;
            }
        }

        if(n == 0){
            ans.push_back(str);
            return;
        }

        // include 0
        str.push_back('0');
        solve(n - 1 , str , ans);
        str.pop_back();

        // include 1
        str.push_back('1');
        solve(n - 1 , str , ans);
        str.pop_back();
    }


    vector<string> validStrings(int n) {
        
        vector<string>ans;

        string str = "";

        solve(n , str , ans);

        return ans;
    }
};