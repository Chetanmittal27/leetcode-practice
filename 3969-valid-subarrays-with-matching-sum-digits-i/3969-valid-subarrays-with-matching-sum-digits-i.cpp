class Solution {
public:

    int checkDigits(long long num , int x){
        int first_digit = (num % 10);
        num = num / 10;

        if(first_digit != x){
            return 0;
        }

        int last_digit;

        while(num > 0){

            if(num < 10){
                last_digit = num;
            }

            num = num / 10;
        }

        if(last_digit != x){
            return 0;
        }

        return 1;
    }


    int countValidSubarrays(vector<int>& nums, int x) {
        
        int n = nums.size();

        int count = 0;

        for(int i = 0; i < n; i++){

            long long sum = 0;

            for(int j = i; j < n; j++){

                sum = sum + (long long)nums[j];

                if(sum < 10){
                    if(sum == x){
                        count++;
                    }
                }

                else{
                    int check = checkDigits(sum , x);
                    count = count + check;
                }
            }
        }

        return count;
    }
};