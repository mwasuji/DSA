class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode* ans = new ListNode(-1); // dummy node
        ListNode* mptr = ans;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            } else {
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }

        if (list1) {
            mptr->next = list1;
        }
        if (list2) {
            mptr->next = list2;
        }

        return ans->next; // ✅ return the head of the merged list
    }
};
