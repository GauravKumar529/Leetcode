
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode reverseList(ListNode head) {
        // Base case: if list is empty or has one node
        if (head == null || head.next == null) {
            return head;
        }

        // Recursive call to reverse the rest
        ListNode newHead = reverseList(head.next);

        // Reverse the current node's link
        ListNode front = head.next;
        front.next = head;
        head.next = null;

        return newHead;
    }
}
