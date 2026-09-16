class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n = s.length();

        vector<bool>vis(26 , false);
        vector<int>temp(26 , -1);

        for(int i = 0; i < n; i++){
            temp[s[i] - 'a'] = i;
        }

        string ans = "";

        for(int i = 0; i < n; i++){

            if(vis[s[i] - 'a']){
                continue;
            }

            while(!ans.empty() && s[i] < ans.back() && temp[ans.back() - 'a'] > i){

                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            vis[s[i] - 'a'] = true;
            ans.push_back(s[i]);
        }

        return ans;
    }
};