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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL){
            len++;
            temp = temp -> next;
        }

        temp = head;

        int x = len - (k % len);

        if(x == len){

            return head;
        }

        int count = 1;

        while(temp != NULL){
            
            if(count == x){
                break;
            }

            temp = temp -> next;
            count++;
        }

        ListNode* newHead = temp -> next;
        temp -> next = NULL;

        ListNode* prev = newHead;

        while(prev -> next != NULL){
            prev = prev -> next;
        }

        prev -> next = head;

        return newHead;
    }
};