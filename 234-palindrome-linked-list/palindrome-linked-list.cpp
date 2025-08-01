class Solution {
public:
    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find middle
        ListNode* mid = getmid(head);

        // Step 2: Reverse from mid onwards (important for even length)
        ListNode* secondHalfHead = reverse(mid);

        // Step 3: Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = secondHalfHead;

        while (head2 != NULL) {
            if (head1->val != head2->val) {
                // Restore original list (optional)
                reverse(secondHalfHead);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Optional: Restore the list
        reverse(secondHalfHead);

        return true;
    }
};
