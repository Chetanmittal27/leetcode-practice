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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(temp1 != NULL || temp2 != NULL || carry != 0){

            int sum = carry;

            if(temp1 != NULL){
                sum = sum + temp1 -> val;
                temp1 = temp1 -> next;
            }

            if(temp2 != NULL){
                sum = sum + temp2 -> val;
                temp2 = temp2 -> next;
            }

            
            ListNode* x = new ListNode(sum % 10);
            temp -> next = x;
            temp = temp -> next;
            carry = sum / 10;
        }

        return dummyNode -> next;
    }
};