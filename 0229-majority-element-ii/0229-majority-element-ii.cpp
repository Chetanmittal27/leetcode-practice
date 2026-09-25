class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int count1 = 0 , ele1 = -1;
        int count2 = 0 , ele2 = -1;

        for(int i = 0; i < n; i++){

            if(count1 == 0 && nums[i] != ele2){
                ele1 = nums[i];
                count1 = 1;
            }

            else if(count2 == 0 && nums[i] != ele1){
                ele2 = nums[i];
                count2 = 1;
            }

            else if(nums[i] == ele1){
                count1++;
            }

            else if(nums[i] == ele2){
                count2++;
            }

            else{
                count1--;
                count2--;
            }
        }


        int cnt1 = 0 , cnt2 = 0;

        for(int i = 0; i < n; i++){

            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }

        vector<int>ans;

        if(cnt1 > n/3) ans.push_back(ele1);
        if(cnt2 > n/3 && ele2 != ele1) ans.push_back(ele2);


        return ans;
    }
};