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
    ListNode* middleNode(ListNode* head) {
        using Node  = ListNode ;
        if(head == NULL) return NULL;
        if(head->next == NULL) return head ;
        Node* slow = head ;
        Node* fast = head ;
        while(fast !=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow ;
        /// this is a hare tortoise methid algo in which slow pointer move by one other by two place sand chech condition and finally slow wiill be poinyting to middle one 
        





        
    }
};