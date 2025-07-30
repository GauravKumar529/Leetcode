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
Node* findNode(int val ,Node* head) {
    Node* temp = head ;
  //  Node* prevNode = nullptr;
    --val;
    while(temp && val > 0) {
        val--;
       // prevNode = temp;
        temp = temp->next ;
    }
    return temp;
}
Node* reverseLinkedList(Node* head) {
    Node* temp  = head ;
    Node* prevNode = nullptr ;
   
    while(temp ) {
        Node* nextNode = temp->next ;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode ;
    }
    return prevNode;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr  ) return head ;
        if(left == right ) return head;
        Node* temp  = head ;
        Node* leftNode = temp;
        Node* prevNode  = nullptr;
        Node* rightNode = nullptr;
        if(left == 1)  rightNode = findNode( right ,  temp);
        else {
            prevNode = findNode( left - 1 , temp);
            rightNode = findNode( right ,  temp);
            leftNode  = prevNode->next ;
        } 
        Node* rightNext = rightNode->next ; 
        rightNode->next = nullptr ;
        Node* reverseLL = reverseLinkedList(leftNode);
        if(prevNode) prevNode->next = reverseLL;
        else head = reverseLL; //  focus on this   this is my mistake i missed this why 
        Node* tail = reverseLL;// intead of soing right
        while (tail->next) tail = tail->next;
        tail->next = rightNext;
        return head ;
    }
};
//