class Solution {
public:
    
    void merge(vector<int>& nums , int n , int low , int high){

        int mid = (low + high) / 2;

        int left = low;
        int right = mid + 1;

        vector<int>temp;

        while(left <= mid && right <= high){

            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }

            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }


        for(int i = 0; i < temp.size(); i++){

            nums[i + low] = temp[i];
        }
    }


    void merge_sort(vector<int>& nums , int n , int low , int high){
        if(low >= high){
            return;
        }

        int mid = (low + high) / 2;

        merge_sort(nums , n , low , mid);
        merge_sort(nums , n , mid+1 , high);
        merge(nums , n , low , high);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();

        merge_sort(nums , n , 0 , n - 1);

        return nums;
    }
};