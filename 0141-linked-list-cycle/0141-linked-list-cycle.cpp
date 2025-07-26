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
    bool hasCycle(ListNode *head) { ///  hthis is a damn problem bexcz , people firstly do not understand what actually problem says and how we do , even i do not think about the brute force as well ;
        using Node = ListNode ;
        Node* slow = head ;
        Node* fast = head ;
        if(head == NULL || head->next == NULL) return false ;
        while(fast!= nullptr && fast->next != nullptr  ) {
            slow = slow->next;
            fast = fast->next->next ;
            if(fast == slow) return true ;
        }
        return false ;

        
        
    }
};