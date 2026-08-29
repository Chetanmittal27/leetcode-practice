class Solution {
public:

    int gcd(int a , int b){
        
        while(b != 0){
            int temp = (a % b);
            a = b;
            b = temp;
        }

        return a;
    }

    
    int maxValidSplits(vector<int>& nums) {

        int n = nums.size();

        int maxi = 0;
        
        vector<int>prefix(n , 1);
        vector<int>suffix(n , 1);

        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1; i < n; i++){
            prefix[i] = gcd(nums[i] , prefix[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            suffix[i] = gcd(nums[i] , suffix[i+1]);
        }

        int count = 0;

        for(int i = 0; i < n-1; i++){
            if(prefix[i] == suffix[i+1]){
                count++;
            }
        }

        maxi = max(maxi , count);

        for(int j = 0; j < n; j++){

            vector<int>arr;

            for(int k = 0; k < n; k++){
                if(k != j){
                    arr.push_back(nums[k]);
                }
            }

            int m = arr.size();
            vector<int>start(m);
            vector<int>end(m);
            start[0] = arr[0];
            end[m-1] = arr[m-1];

            for(int k = 1; k < m; k++){
                start[k] = gcd(arr[k] , start[k-1]);
            }

            for(int k = m-2; k >= 0; k--){
                end[k] = gcd(arr[k] , end[k+1]);
            }

            int cnt = 0;
            
            for(int k = 0; k < m-1; k++){
                if(start[k] == end[k+1]){
                    cnt++;
                }
            }

            maxi = max(maxi , cnt);
        }

        return maxi;
    }
};