
class Solution {
public:
    using Node = ListNode;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;

        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        Node* head = nullptr;

        while (!st1.empty() || !st2.empty() || carry > 0) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }

            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            carry = sum / 10;
            Node* newNode = new Node(sum % 10);

            // Head insert
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};
