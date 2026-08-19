class Solution {
public:

    bool isAvailable(unordered_map<int,unordered_set<int>>& mpp , int row , int seat){

        if(mpp[row].find(seat) == mpp[row].end()){
            return true;
        }

        return false;
    }


    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int , unordered_set<int>>mpp;

        for(int i = 0; i < reservedSeats.size(); i++){
            int row = reservedSeats[i][0];
            int col = reservedSeats[i][1];

            mpp[row].insert(col);
        }

        int count = 0;

        count = count + (n - mpp.size()) * 2;

        for(auto it : mpp){

            int row = it.first;

            bool groupA = isAvailable(mpp , row , 2) && isAvailable(mpp , row , 3) && isAvailable(mpp , row , 4) && isAvailable(mpp , row , 5);

            bool groupB = isAvailable(mpp , row , 4) && isAvailable(mpp , row , 5) && isAvailable(mpp , row , 6) && isAvailable(mpp , row , 7);

            bool groupC = isAvailable(mpp , row , 6) && isAvailable(mpp , row , 7) && isAvailable(mpp , row , 8) && isAvailable(mpp , row , 9);

            
            if(groupA && groupC){
                count = count + 2;
            }

            else if(groupA || groupB || groupC){
                count = count + 1;
            }
        }

        return count;
    }
};