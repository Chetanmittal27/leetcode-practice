class Solution {
public:
    bool isUgly(int n) {
        
        vector<int>arr = {2,3,5};

        int i = 0;

        while(i < 3 && n > 1){

            if(n % arr[i] == 0){
                n = n / arr[i];
            }

            else{
                i++;
            }
        }

        return n == 1 ? true : false;
    }
};