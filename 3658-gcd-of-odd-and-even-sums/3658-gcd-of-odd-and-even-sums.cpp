class Solution {
public:

    int GCD(int m , int x){

        while(x > 0){
            int temp = m % x;
            m = x;
            x = temp;
        }

        return m;
    }


    int gcdOfOddEvenSums(int n) {
        
        int sumOdd = 0 , sumEven = 0;

        for(int num = 1; num <= n*2; num++){

            if((num % 2) == 0){

                sumEven = sumEven + num;
            }

            else{
                sumOdd = sumOdd + num;
            }
        }


        return GCD(sumOdd , sumEven);
    }
};