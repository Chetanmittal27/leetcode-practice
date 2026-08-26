class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.length();
        
        int l = 0 , r = 0;
        int count = 0 , ans = INT_MAX , idx = -1;

        map<int , set<string>>mpp;

        while(r < n){

            if(s[r] == '1'){
                count++;
            }

            while(count == k){
                if((r - l + 1) < ans){
                    mpp[r-l+1].insert(s.substr(l , r - l + 1));
                }

                if(s[l] == '1'){
                    count--;
                }

                l++;
            }

            r++;
        }

        if(mpp.empty()) return "";

        return *mpp.begin()->second.begin();
    }
};