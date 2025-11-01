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
    // Linked List → Array
    vector<int> linkedListToArray(ListNode* head) {
        vector<int> arr;
        ListNode* curr = head;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        return arr;
    }

    // Array → Linked List
    ListNode* arrayToLinkedList(const vector<int>& arr) {
        if (arr.empty()) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    // Remove nums[] elements from linked list
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> nums2 = linkedListToArray(head);
        vector<int> res;

        unordered_set<int> st(nums.begin(), nums.end());

        for (int x : nums2) {
            if (st.find(x) == st.end()) { // keep elements NOT in nums
                res.push_back(x);
            }
        }

        ListNode* NewHead = arrayToLinkedList(res);
        return NewHead;
    }
};
