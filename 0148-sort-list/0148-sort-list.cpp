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

Node* mergeLL(Node* left, Node* right){

    Node* temp  = new Node(-1); //  creating a dummynode   -> its a nice concept of reolacing the space using any new data structure 
    Node* tempHead  = temp;
    while(left && right) {
        if(left->val < right->val) 
        {
            temp->next  = left ;
            left = left->next ;
        }
        else {
            temp->next = right;
            right = right->next ;
        }
        temp = temp->next ;
    }
    while(left!= nullptr ) {
        temp ->next =   left ;
        left = left-> next ;
         temp = temp->next ;  
    }
    while(right != nullptr){
        temp->next = right;
        right = right->next ;
        temp = temp->next ;  
    }
    return tempHead->next ;
}
Node* findMiddle(Node* head) {
     Node* slow = head ;
     Node* fast = head ->next ;// slight change in this to keep our middle for even no of nodes  , the first one middle // do a dry run for the even size elements 
     while(fast !=NULL && fast->next != NULL)
     {
        slow = slow->next;
        fast = fast->next->next;
     }
     return slow ;
}
    ListNode* sortList(ListNode* head) {
        using Node = ListNode ;
        if(head == nullptr || head->next == NULL) return head ;
    // find the miidle of ll using slow and fast pointer 
        Node* mid = findMiddle(head ); 
        Node* leftHead = head ;
        Node* rightHead = mid->next ;
        mid ->next = nullptr ;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return  mergeLL( leftHead  , rightHead ); //  this is a catchy and my mistake , in ll you must have to return the head of updarted l that why i do this 
      
      
      
        // my mistake i will merge LL and then return the head instead of returning  mergeLL()  
    }
};
// what will i learn from this problem -> sy  how to merge two ll without usng extra space instead i will be uding a dummynode and pointing the right element to the next od dummyNode ;
//2-> merge two  singly linked list in a sorted order  ;

