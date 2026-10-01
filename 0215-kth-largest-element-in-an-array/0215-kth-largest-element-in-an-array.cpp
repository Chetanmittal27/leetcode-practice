class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int n = nums.size();

        priority_queue<int>maxHeap;

        for(int i = 0; i < n; i++){

            maxHeap.push(nums[i]);
        }

        while(k > 0){

            int val = maxHeap.top();
            maxHeap.pop();

            k--;

            if(k == 0){
                return val;
            }
        }

        return -1;
    }
};