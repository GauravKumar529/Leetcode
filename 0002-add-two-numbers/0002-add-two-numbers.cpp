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
using Node = ListNode ;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr  && l2 == nullptr ) return NULL;
        Node* t1 = l1;
        Node* t2 = l2;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode ;
        int carry = 0;
        while(t1 != nullptr  || t2 != nullptr) {
           int  sum = carry ;
            if(t1)  sum+=t1->val;
            if(t2) sum += t2->val;
            Node* newNode = new Node (sum%10);
            carry = sum / 10;
            curr->next  = newNode;
            curr = newNode ;
            if(t1) t1= t1->next ;
            if(t2) t2 = t2->next ;
        } 
        if(carry == 1) {
            Node* newNode = new Node(carry );
            curr->next = newNode ;
           
        }
         return dummyNode->next ;
        
        
    }
};