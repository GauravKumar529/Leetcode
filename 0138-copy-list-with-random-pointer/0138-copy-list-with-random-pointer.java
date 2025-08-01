/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return  null;
        Node temp = head;
         // step 1
        while(temp!= null) {
            Node copyNode = new Node ( temp.val);
            copyNode.next  = temp.next ;
            temp.next = copyNode ;
            temp = temp.next.next ;
        }
         // step 2
        temp = head ;
       
        while(temp!=null ) {
            Node copyNode = temp.next ;
            if(temp.random!=null) copyNode .random = temp.random.next  ; // why  random. next lets dry run this on my notebook  if i  have 1 -> 1' -> 2 -> 2' -> 3 -> 3' -> null ,, value ' will be inserted one , and if temp->random will be pointing to a temp->value and that value_next will be theco[yNode  random value  that will it will pointing to temp.random.next , NOT temp.random]
            else {
                copyNode.random = null;
            }
            temp = temp.next .next ;
        }
        // 3rd pass  step 3
        temp = head ;
        Node dummyNode = new Node(-1); // creating a new List 
        Node  newHead = dummyNode ;
        while(temp != null) {
            dummyNode.next = temp.next ;
            temp.next = temp.next.next ;
            dummyNode = dummyNode.next ;
            temp = temp.next ; 
        }
        return newHead.next ;
    }
}