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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head ;
        if(head == NULL) return NULL; 
        while(temp!= NULL) {
            cnt++;
            temp = temp-> next;
        }
        int position = cnt - n +1;
        if(position  == 1) {
            ListNode* newHead  = head->next;
            delete(head );
            return newHead ;
        }
        temp =  head ;
        ListNode* prev = NULL;
        cnt = 0;
        while(temp != NULL) {
            cnt++;
            if(cnt ==  position ) {
                prev->next  = temp->next ;
                delete(temp);
                break;
            }
            prev = temp;
            temp = temp-> next ;
        }
        return head ; 
    }
};