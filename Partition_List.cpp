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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *less = lessThan(head, x);
        ListNode *greater = greaterThan(head, x);
        if (less == NULL) return greater;
        ListNode *copy = less;
        while (copy->next != NULL) copy = copy->next;
        copy->next = greater;
        return less;
    }
    ListNode *lessThan(ListNode *head, int x) {
        if (head == NULL) return NULL;
        if (head->val < x) {
            ListNode *l = new ListNode(head->val);
            l->next = lessThan(head->next, x);
            return l;
        } else return lessThan(head->next, x);
    }
    ListNode *greaterThan(ListNode *head, int x) {
        if (head == NULL) return NULL;
        if (head->val >= x) {
            ListNode *l = new ListNode(head->val);
            l->next = greaterThan(head->next, x);
            return l;
        } else return greaterThan(head->next, x);
    }
};