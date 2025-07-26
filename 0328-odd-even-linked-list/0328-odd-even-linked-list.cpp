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
    ListNode* oddEvenList(ListNode* head) {
        using Node = ListNode ;
        if(head == nullptr ) return NULL;
        if(head->next == NULL)  return head ;
        Node* evenHead = head->next ;
        Node* even = head->next ;
        Node* odd = head;
        while(even && even->next && odd->next  ) {
            odd->next  = even->next  ;
            odd = odd->next ;

            even->next = even->next->next;
            even = even->next ;
        }
        odd->next = evenHead;
        return head ;

    }
};
// two thing i have learned from this problem i.e , 
//1-> hw can i tranverse in odd and evwn indices position in a one traverse  without using any extra  thins where i am links that odd and even links simultaneously 
// here , i understand how a  two node simultaneiusly  can be linked to another links  in a traverse without use any space to storing it /
// how Y FIX IT -> instead of storing data somewhere you must do links the next pointer to even and odd indices nodes simultaneously but individuallty and finally connect the two nodes each other 
//2.-> when u do odd.next = odd.next.next and after you mive the odd pointer ( what is wrong -> odd->next . next ) (write -> thought process since you do odd->next -> odd will move one place  after the odd  so i ll do odd->next instead of previos one )/// MAJOR DOUBT WHICH CAN BE HANDLE BY VISUALIZE THE MOVEMENT OF NODES POINTER