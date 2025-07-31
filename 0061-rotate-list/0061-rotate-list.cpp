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
Node* findNode( Node* head , int val) {
    --val;
    Node* temp = head;
    while(temp && val >0) {
        temp = temp->next ;
        val--;
    }
    return temp;
} 
    ListNode* rotateRight(ListNode* head, int k) { 
        if(head == nullptr || head->next == nullptr ) return head ;
        Node* temp1 = head ;
        Node* temp2 = head ;
        int cnt = 1;
        while(temp1->next) {
            cnt++;
            temp1  = temp1->next ;

        }
        if(k% cnt  == 0) return  head ; //  this is also a edge case which i muddes so you have to think abbout null ,one , two , three , all , order ,pattern for finding the edge cases 
        int val = cnt  - k% cnt  ; //  this is a  conceptual pount where i am lagging 
        Node* prevNode = findNode(temp2 , val);
        Node* newHead = prevNode->next ;
        prevNode->next = nullptr ;
        temp1 ->next = head ;
        return newHead ;
    
    }
};