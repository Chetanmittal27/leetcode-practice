class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {

        int srcSum = source[0] + source[1];
        int targetSum = target[0] + target[1];

        if((srcSum % 2 == 0  &&  targetSum % 2 != 0)  ||  (srcSum % 2 != 0  &&  targetSum % 2 == 0)){

            return -1;
        }

        if(source[0] == source[1]  &&  target[0] == target[1]) return 1;

        if(abs(source[0] - target[0]) == abs(source[1] - target[1])){
            return 1;
        }

        return 2;
    }
};