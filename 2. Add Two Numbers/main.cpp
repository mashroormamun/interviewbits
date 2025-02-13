#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *sum = NULL, *headSum = NULL;

        // while(l1!=NULL && l2!=NULL) {
        //     int add = (l1->val + l2->val + carry)%10;
        //     carry = (l1->val + l2->val + carry)/10;

        //     if(sum == NULL) {
        //         headSum = sum = new ListNode(add);
        //     } else {
        //         sum->next = new ListNode(add);
        //         sum = sum->next;
        //     }

        //     l1 = l1->next;
        //     l2 = l2->next;
        // }

        while(l1!=NULL || l2!=NULL) {
            int l1_val = 0;
            int l2_val = 0;

            if(l1!=NULL) {
                l1_val = l1->val;
                l1 = l1->next;
            }

            if(l2!=NULL) {
                l2_val = l2->val;
                l2 = l2->next;
            }

            int add = (l1_val + l2_val + carry)%10;
            carry = (l1_val + l2_val + carry)/10;

            if(sum == NULL) {
                headSum = sum = new ListNode(add);
            } else {
                sum->next = new ListNode(add);
                sum = sum->next;
            }

        }

        if (carry != 0) {
            sum->next = new ListNode(carry);
                sum = sum->next;
        }

        return headSum;
    }
};

ListNode* initializeLinkListFromVector(vector<int> &vec) {
    ListNode *temp = NULL, *head=NULL;
    for (int i=0;i<vec.size();i++) {
        if(head == NULL) {
            head = temp = new ListNode(vec[i]);
        } else {
            temp->next = new ListNode(vec[i]);
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    printf("============================================\n");

    vector<int> v1{9,9,9,9,9};
    ListNode* l1 = initializeLinkListFromVector(v1);

    vector<int> v2{1};
    ListNode* l2 = initializeLinkListFromVector(v2);

    Solution s;
    ListNode* sum = s.addTwoNumbers(l1, l2);

    for (;sum != NULL;) {
        printf("%d ", sum->val);
        sum = sum->next;
    }

    printf("\n============================================\n");

    return 0;
}