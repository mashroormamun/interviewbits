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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head, *ptr;

        if (list1==nullptr)
            return list2;
            
        if (list2==nullptr) 
            return list1;

        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ptr = head;

        while(list1!=nullptr && list2!=nullptr) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                ptr = ptr->next;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                ptr = ptr->next;
                list2 = list2->next;
            }
        }

        if (list1!=nullptr) {
            ptr->next = list1;
        }

        if (list2!=nullptr) {
            ptr->next = list2;
        }

        return head;
    }
};