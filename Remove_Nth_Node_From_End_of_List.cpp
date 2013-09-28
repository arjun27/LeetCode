/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // easy solution: stack (2 passes)
        // use 2 pointers with n nodes in between
        ListNode *ahead, *back;
        ahead = head; back = head;
        for (int i = 0; i < n; i++) ahead = ahead->next;
        if (ahead == NULL) return head->next;
        while (ahead->next != NULL) {
            ahead = ahead->next;
            back = back->next;
        }
        back->next = back->next->next;
        return head;
    }
};