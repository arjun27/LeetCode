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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) return head;
        if (k == 0) return head;
        ListNode *last = head;
        ListNode *secondLast;
        while (last->next != NULL) {
            secondLast = last;
            last = last->next;
        }
        last->next = head;
        secondLast->next = NULL;
        return rotateRight(last, k-1);
    }
};