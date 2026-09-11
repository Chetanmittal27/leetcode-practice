class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        vector<int>temp(26 , 0);

        for(auto ch : chars){
            temp[ch - 'a']++;
        }

        int ans = 0;

        for(auto word : words){
            vector<int>arr(26 , 0);

            for(auto ch : word){
                arr[ch - 'a']++;
            }

            bool isCheck = true;
            for(int i = 0; i < 26; i++){
                if(arr[i] > temp[i]){
                    isCheck = false;
                    break;
                }
            }

            ans = ans + (isCheck == true ? word.length() : 0);
        }

        return ans;
    }
};