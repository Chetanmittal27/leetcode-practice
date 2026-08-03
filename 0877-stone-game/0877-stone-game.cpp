class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();

        int l = 0 , r = n - 1;

        int aliceStones = 0 , bobStones = 0;

        while(l < r){

            if(piles[l] <= piles[r]){
                aliceStones = aliceStones + piles[r];
                bobStones = bobStones + piles[l];
            }

            else{
                aliceStones = aliceStones + piles[l];
                bobStones = bobStones + piles[r];
            }

            l++;
            r--;
        }

        return aliceStones > bobStones ? true : false;
    }
};