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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // splicing together!
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode *l;
        if (l1 == NULL) {
            l = new ListNode(l2->val);
            l->next = mergeTwoLists(l1, l2->next);
            return l;
        }
        if (l2 == NULL) {
            l = new ListNode(l1->val);
            l->next = mergeTwoLists(l1->next, l2);
            return l;
        }
        if (min(l1->val, l2->val) == l2->val) {
            l = new ListNode(l2->val);
            l->next = mergeTwoLists(l1, l2->next);
            return l;
        } else {
            l = new ListNode(l1->val);
            l->next = mergeTwoLists(l1->next, l2);
            return l;
        }
    }
    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};