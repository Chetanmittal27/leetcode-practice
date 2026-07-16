class Solution {
public:

    int CalGCD(int m , int x){

        while(x > 0){
            int temp = m % x;
            m = x;
            x = temp;
        }

        return m;
    }


    long long gcdSum(vector<int>& nums) {
        
        int n = nums.size();

        vector<int>prefixMax(n , 0);
        prefixMax[0] = nums[0];

        int maxi = nums[0];

        for(int i = 1; i < n; i++){
            maxi = max(maxi , nums[i]);
            prefixMax[i] = maxi;
        }

        vector<int>prefixGcd(n);

        for(int i = 0; i < n; i++){

            prefixGcd[i] = CalGCD(nums[i] , prefixMax[i]);
        }


        sort(prefixGcd.begin() , prefixGcd.end());

        int l = 0 , r = n - 1;

        long long sum = 0;

        while(l < r){

            int val = CalGCD(prefixGcd[l] , prefixGcd[r]);

            sum = sum + (long long)(val);
            l++;
            r--;
        }

        return sum;
    }
};