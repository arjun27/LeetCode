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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return addTwoNumbers(l1, l2, 0);
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if (l1 == NULL && l2 == NULL) {
            if (carry == 1) {
                ListNode *res = new ListNode(1);
                return res;
            }
            return NULL;
        }
        if (l1 == NULL) {
            int newVal = l2->val + carry;
            ListNode *res = new ListNode(newVal % 10);
            res->next = addTwoNumbers(NULL, l2->next, (newVal >= 10) ? 1 : 0);
            return res;
        }
        if (l2 == NULL) {
            int newVal = l1->val + carry;
            ListNode *res = new ListNode(newVal % 10);
            res->next = addTwoNumbers(l1->next, NULL, (newVal >= 10) ? 1 : 0);
            return res;
        }
        int newVal = l1->val + l2->val + carry;
        ListNode *res = new ListNode(newVal % 10);
        res->next = addTwoNumbers(l1->next, l2->next, (newVal >= 10) ? 1 : 0);
        return res;
    }
};