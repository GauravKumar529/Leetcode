/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        using Node = ListNode ;
        Node* slow = head ;
        Node* fast = head ;
        if(head == NULL || head->next == NULL) return NULL ;
        while(fast!= nullptr && fast->next != nullptr  ) { // this will safe my fast->next -next and why is it do a dry run 
            slow = slow->next;
            fast = fast->next->next ;
            if(fast == slow) break;
        }
        if (slow!= fast ) return NULL;
        // NOW , i am  surely say that there will be a starting point , since loop is detedt ed , that is step 1 
        slow = head ;
        while(slow != fast ) {
            slow = slow->next ;
            fast = fast->next ;
        }
        return fast;
    }
};