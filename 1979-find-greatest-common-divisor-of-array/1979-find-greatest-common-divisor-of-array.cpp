class Solution {
public:

    int GCD(int m , int n){

        while(n > 0){
            int temp = m % n;
            m = n;
            n = temp;
        }

        return m;
    }


    int findGCD(vector<int>& nums) {
        
        int smallest = *min_element(nums.begin() , nums.end());
        int largest = *max_element(nums.begin() , nums.end());

        return GCD(smallest , largest);
    }
};