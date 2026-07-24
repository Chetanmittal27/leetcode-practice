class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        int n = s.length();

        int result = 0;

        for(int i = 0; i < s.length(); i++){

            if(s[i] == '1'){
                result++;
            }
        }

        
        vector<int>zeroBlocks;

        int i = 0;
        while(i < n){

            if(s[i] == '0'){

                int count = 0;
                while(i < n  &&  s[i] == '0'){
                    count++;
                    i++;
                }

                zeroBlocks.push_back(count);
            }

            else{
                i++;
            }
        }

        
        int newActive = 0;
        for(int j = 1; j < zeroBlocks.size(); j++){
            newActive = max(newActive , zeroBlocks[j] + zeroBlocks[j-1]);
        }

        return result + newActive;
    }
};