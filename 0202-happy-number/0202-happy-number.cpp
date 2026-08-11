class Solution {
public:
    bool isHappy(int n) {
        
        while(n > 1){

            if(n < 7) return false;

            int num = n , sum = 0;

            while(num > 0){
                int val = (num % 10);
                sum = sum + pow(val , 2);
                num = num / 10;
            }

            n = sum;
        }

        if(n == 1) return true;
        return false;
    }
};