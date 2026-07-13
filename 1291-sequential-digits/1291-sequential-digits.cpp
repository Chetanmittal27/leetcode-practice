// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {
        
//         vector<int>ans;

//         for(int num = low; num <= high; num++){

//             int number = num;
//             int lastDigit = (number % 10);

//             number = number / 10;

//             bool isSequential = true;

//             while(number > 0){

//                 int val = (number % 10);

//                 if(val != lastDigit - 1){
//                     isSequential = false;
//                     break;
//                 }

//                 lastDigit = val;
//                 number = number / 10;
//             }

//             if(isSequential){
//                 ans.push_back(num);
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        
        vector<int>ans;

        for(int i = 1; i <= 9; i++){

            int start = i;
            int num = 0;

            while(start <= 9){

                num = (num * 10) + start;

                if(num > high) break;
                if(num >= low  &&  num <= high){
                    ans.push_back(num);
                }

                start++;
            }
        }


        sort(ans.begin() , ans.end());

        return ans;
    }
};