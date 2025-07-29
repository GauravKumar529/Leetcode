
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
    ListNode* swapPairs(ListNode* head) {
        using Node = ListNode;
        
        Node* dummy = new Node(-1);   // dummy node
        dummy->next = head;
        Node* prev = dummy;

        while (prev->next && prev->next->next) {
            Node* first = prev->next;
            Node* second = prev->next->next;

            // Swapping
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move prev two nodes ahead
            prev = first;
        }

        return dummy->next;
    }
};
