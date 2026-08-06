class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for(int i = n; i <= 100; i++){

            int num = i;
            int product = 1;

            while(num > 0){
                product = product * (num % 10);
                num = num / 10;
            }

            if(product % t == 0){
                return i;
            }
        }

        return -1;
    }
};