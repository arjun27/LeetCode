class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverser(head, k);
    }
    ListNode *reverser(ListNode *head, int k) {
        if (head == NULL) return NULL;
        int i = 0;
        ListNode *final = head;
        while (++i < k) {
            final = final->next;
            if (final == NULL) return head;
        }
        ListNode *remaining = reverser(final->next, k);
        ListNode *copy = head->next, *prev = head, *temp;
        for (i = 1; i < k; i++) {
            temp = copy->next;
            copy->next = prev;
            prev = copy;
            copy = temp;
        }
        head->next = remaining;
        return final;
    }
};
