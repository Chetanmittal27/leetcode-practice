class Solution {
public:
    string reverseVowels(string s) {
        
        int n = s.length();

        vector<char>arr;

        for(int i = 0; i < n; i++){

            char ch = tolower(s[i]);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){

                arr.push_back(s[i]);
            }
        }

        reverse(arr.begin() , arr.end());

        int j = 0;

        for(int i = 0; i < n; i++){

            char ch = tolower(s[i]);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){

                s[i] = arr[j];
                j++;
            }
        }

        return s;
    }
};