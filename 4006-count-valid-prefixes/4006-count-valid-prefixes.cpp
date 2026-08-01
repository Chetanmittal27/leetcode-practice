class Solution {
public:
    int countValidPrefixes(string s) {
        
        int n = s.length();
        int ones = 0 , zeros = 0;

        int count = 0;

        for(int i = 0; i < n; i++){

            if(s[i] == '0'){
                zeros++;
            }

            else{
                ones++;
            }

            if(ones == zeros || (ones + 1) == zeros || (zeros + 1) == ones){
                count++;
            }
        }

        return count;
    }
};