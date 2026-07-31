class Solution {
public:
    int maxDistance(string moves) {
        
        int x = 0 , y = 0;

        int n = moves.length();

        if(n == 1){
            return 1;
        }

        int i = 0;
        int underscore = 0;

        while(i < n){

            if(moves[i] == 'U'){
                y++;
            }

            else if(moves[i] == 'D'){
                y--;
            }

            else if(moves[i] == 'L'){
                x--;
            }

            else if(moves[i] == 'R'){
                x++;
            }

            else{
                underscore++;
            }

            i++;
        }

        int distance = abs(x - 0) + abs(y - 0) + underscore;

        return distance;
    }
};