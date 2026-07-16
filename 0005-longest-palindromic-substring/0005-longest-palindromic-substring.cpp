// class Solution {
// public:

//     bool checkPalindrome(string &s , int l , int r , vector<vector<bool>>& dp){

//         if(l >= r){
//             return true;
//         }

//         if(dp[l][r] == true){
//             return true;
//         }

//         if(s[l] != s[r]){
//             return false;
//         }

//         dp[l][r] = checkPalindrome(s , l + 1 , r - 1 , dp);
//         return dp[l][r];
//     }


//     string longestPalindrome(string s) {
        
//         int n = s.length();

//         int maxi = 0;
//         string ans = "";

//         int idx = -1;

//         vector<vector<bool>>dp(n , vector<bool>(n , false));

//         for(int i = 0; i < n; i++){

//             for(int j = i; j < n; j++){

//                 if(checkPalindrome(s , i , j , dp) && (j - i + 1) > maxi){

//                     maxi = j - i + 1;
//                     idx = i;
//                 }
//             }

//         }

//         return s.substr(idx , maxi);
//     }
// };



class Solution {
public:

    string longestPalindrome(string s) {
        
        int n = s.length();

        int maxi = 1;
        int idx = 0;

        vector<vector<bool>>dp(n , vector<bool>(n , false));

        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }


        for(int len = 2; len <= n; len++){

            for(int i = 0; i < n-len+1; i++){

                int j = i + len - 1;

                if(s[i] == s[j]  &&  len == 2){
                    dp[i][j] = true;
                    maxi = len;
                    idx = i;
                }

                else if(s[i] == s[j]  &&  dp[i+1][j-1] == true){
                    dp[i][j] = true;
                    maxi = len;
                    idx = i;
                }


                else{
                    dp[i][j] = false;
                }
            }
        }

        return s.substr(idx , maxi);
    }
};