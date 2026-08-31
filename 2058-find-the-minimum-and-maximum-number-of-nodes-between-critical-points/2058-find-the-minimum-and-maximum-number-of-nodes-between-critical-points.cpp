/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int>arr;

        ListNode* temp = head;

        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        vector<int>result;

        for(int i = 1; i < arr.size() - 1; i++){

            if(arr[i] > arr[i-1]  &&  arr[i] > arr[i+1]){
                result.push_back(i);
            }

            else if(arr[i] < arr[i-1]  &&  arr[i] < arr[i+1]){
                result.push_back(i);
            }
        }

        if(result.size() < 2) return {-1 , -1};

        int mini = INT_MAX;

        for(int i = 0; i < result.size()-1; i++){
            mini = min(result[i+1]-result[i] , mini);
        }

        return {mini , result.back() - result[0]};
    }
};