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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *later = swapPairs((head->next->next != NULL) ? head->next->next : NULL);
        ListNode *temp = head->next;
        temp->next = head;
        head->next = later;
        return temp;
    }
};