class Solution {
public:
    int maxScore(string s) {
    
        int n = s.length();

        vector<int>CountZeros(n , 0);
        vector<int>CountOnes(n , 0);

        if(s[0] == '0') CountZeros[0] = 1;

        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                CountZeros[i] = CountZeros[i-1] + 1;
            }

            else{
                CountZeros[i] = CountZeros[i-1];
            }
        }


        for(int i = n-2; i >= 0; i--){
            if(s[i+1] == '1'){
                CountOnes[i] = CountOnes[i+1] + 1;
            }

            else{
                CountOnes[i] = CountOnes[i+1];
            }
        }

        int maxi = 0;

        for(int i = 0; i < n-1; i++){
            maxi = max(maxi , CountZeros[i] + CountOnes[i]);
        }

        return maxi;
    }
};