/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        // Create a dummy node that points to head
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        // Start with dummy node
        ListNode curr = dummy;
        
        // Traverse the list
        while (curr.next != null) {
            if (curr.next.val == val) {
                // Remove the node by skipping it
                curr.next = curr.next.next;
            } else {
                // Move to the next node
                curr = curr.next;
            }
        }
        
        // Return the head of the modified list
        return dummy.next;
    }
}