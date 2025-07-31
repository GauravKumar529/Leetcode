
class Solution {
public:
    using Node = ListNode;

    Node* reverseLinkedList(Node* head) {
        Node* prev = nullptr;
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        Node* revHead = reverseLinkedList(head);

        Node* dummy = new Node(INT_MIN);
        Node* tail = dummy;

        while (revHead) {
            if (revHead->val >= tail->val) {
                // add node
                tail->next = revHead;
                tail = revHead;
            }
            revHead = revHead->next;
        }

        tail->next = nullptr; // break any remaining links

        return reverseLinkedList(dummy->next);
    }
};
