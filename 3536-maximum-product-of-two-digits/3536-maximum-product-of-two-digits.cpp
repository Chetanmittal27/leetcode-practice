class Solution {
public:
    int maxProduct(int n) {
        
        int large = (n % 10);
        int second_large = -1;

        n = n / 10;

        while(n > 0){

            int digit = (n % 10);

            if(digit >= large){
                second_large = large;
                large = digit;
            }

            else if(digit < large && digit > second_large){
                second_large = digit;
            }

            n = n / 10;
        }

        return (large * second_large);
    }
};