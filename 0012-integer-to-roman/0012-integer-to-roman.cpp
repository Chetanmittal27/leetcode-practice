class Solution {
public:
    string intToRoman(int num) {
        
        vector<pair<int , string>>temp = {{1000 , "M"} , {900 , "CM"} , {500 , "D"} , {400 , "CD"} , {100 , "C"} , {90 , "XC"} , {50 , "L"} , {40 , "XL"} , {10 , "X"} , {9 , "IX"} , {5 , "V"} , {4 , "IV"} , {1 , "I"}};

        string ans = "";

        int i = 0;

        while(num > 0){
            if(num >= temp[i].first){
                num = num - temp[i].first;
                ans = ans + temp[i].second;
            }

            else{
                i++;
            }
        }

        return ans;
    }
};