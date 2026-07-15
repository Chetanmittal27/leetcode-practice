class Solution {
public:

    int GCD(int m , int x){

        if(m == 0) return x;
        if(x == 0) return m;

        while(m != x){

            if(m > x){
                m = m - x;
            }

            else{
                x = x - m;
            }
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