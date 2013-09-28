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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 1;
        ListNode *copy = head;
        ListNode *prev = NULL, *start = NULL, *before = NULL, *temp = NULL;
        while (copy != NULL) {
            if (i == m) {
                start = copy;
                if (prev != NULL) {
                    before = prev;
                }
                prev = copy;
                copy = copy->next;
            } else if (i > m && i <= n) {
                temp = copy->next;
                copy->next = prev;
                prev = copy;
                copy = temp;
                if (copy == NULL) { 
                    start->next = NULL;
                    if (before != NULL) before->next = prev;
                    else head = prev;
                }
            } else if (i == n+1) {
                start->next = copy;
                if (before != NULL) before->next = prev;
                else head = prev;
            } else {
                prev = copy;
                copy = copy->next;
            }
            i++;
        }
        return head;
    }
};