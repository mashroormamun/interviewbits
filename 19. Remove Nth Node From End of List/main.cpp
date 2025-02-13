/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l = head;
        int len=0;

        while(l != NULL) {
            len++;
            l = l->next;
        }

        if(n == len) {
            head = head->next;
            return head;
        }

        l = head;
        for(int i=0;i<(len-n-1);i++) {
            l = l->next;
        }

        l->next = l->next->next;
        return head;

    }
};
