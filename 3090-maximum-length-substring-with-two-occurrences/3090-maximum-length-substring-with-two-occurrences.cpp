class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.length();

        int ans = 0;

        int l = 0 , r = 0;
        vector<int>temp(26 , 0);

        while(r < n){
            temp[s[r] - 'a']++;

            while(r < n && temp[s[r] - 'a'] > 2){

                temp[s[l] - 'a']--;
                l++;
            }

            ans = max(ans , r - l + 1);
            r++;
        }

        return ans;
    }
};