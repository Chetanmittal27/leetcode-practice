class Solution {
public:

    bool check3(int num){

        int sum = 0;

        while(num > 0){
            int val = (num % 10);
            sum = sum + val;
            num = num / 10;
        }

        if(sum % 3 == 0) return true;
        return false;
    }


    vector<string> fizzBuzz(int n) {
        
        vector<string>ans;

        for(int i = 1; i <= n; i++){

            if(check3(i) && (i % 5) == 0){
                ans.push_back("FizzBuzz");
            }

            else if(check3(i)){
                ans.push_back("Fizz");
            }

            else if((i % 5) == 0){
                ans.push_back("Buzz");
            }

            else{
                ans.push_back(to_string(i));
            }
        }

        return ans;
    }
};