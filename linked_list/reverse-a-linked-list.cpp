#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // better solution at the bottom
    
    // ListNode* reverseList(ListNode* head) {
    //     if(head == nullptr) return nullptr;

    //     ListNode* h = head;

    //     ListNode* A = head;
    //     ListNode* B;
    //     ListNode* C;

    //     if(head->next != nullptr) {
    //         B = head->next;
    //     } else {
    //         return A;
    //     }

    //     if(B->next == nullptr) {
    //         B->next = A;
    //         A->next = nullptr;
    //         return B;
    //     } else {
    //         C = B->next;
    //     }

    //     A->next = nullptr;

    //     // cout << "---" << endl;
        
    //     while(true) {
    //         // cout << A->val << endl;

    //         if(C == nullptr) {
    //             B->next = A;
    //             return B;
    //             break;
    //         }

    //         B->next = A;

    //         A = B;
    //         B = C;
    //         C = C->next;
    //     }
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};


int main() {
    ListNode *n = new ListNode(1);
    ListNode *head = n;
    
    for(int i=2;i<=10;i++) {
        ListNode *p = new ListNode(i);
        n->next = p;
        n = p;
    }

    Solution s;
    ListNode *rev = s.reverseList(head);

    while(rev != nullptr) {
        cout << rev->val << endl;
        rev = rev->next;
    }


    return 0;
}