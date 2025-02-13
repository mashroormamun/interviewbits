#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode* n1 = reverseList(l1);
        // ListNode* n2 = reverseList(l2);
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* sum_rev = nullptr, *sum_rev_head = nullptr;

        int carry = 0;

        while(n1!=nullptr || n2!=nullptr) {
            int a=0,b=0;

            if(n1!=nullptr) {
                a = n1->val;
                n1 = n1->next;
            }

            if(n2!=nullptr) {
                b = n2->val;
                n2 = n2->next;
            }

            int sum = a + b + carry;
            int num = sum%10;
            carry = sum / 10;

            if(sum_rev == nullptr) {
                sum_rev = new ListNode(num);
                sum_rev_head = sum_rev;
            } else {
                sum_rev->next = new ListNode(num);
                sum_rev = sum_rev->next;
            }

        }

        if (carry != 0) {
            sum_rev->next = new ListNode(carry);
        }

        // ListNode* sum_list = reverseList(sum_rev_head);
        // return sum_list;

        return sum_rev_head;
    }

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

ListNode* createLinkedListFomVec(vector<int> v) {
    if(v.size() == 0) return nullptr;

    ListNode *n = new ListNode(v[0]);
    ListNode *head = n;

    for(int i=1;i<v.size();i++) {
        ListNode *p = new ListNode(v[i]);
        n->next = p;
        n = p;
    }

    return head;
}

int main() {
    vector<int> l1{9,9,9};
    vector<int> l2{1,0,1};

    ListNode* list1 = createLinkedListFomVec(l1);
    ListNode* list2 = createLinkedListFomVec(l2);

    Solution s;
    ListNode *res = s.addTwoNumbers(list1, list2);

    ListNode* rev = res;

    while(rev != nullptr) {
        cout << rev->val << endl;
        rev = rev->next;
    }


    return 0;
}