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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode *node, *mergedList=new ListNode(0);
        node = mergedList;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }

            node = node->next;
        }

        while(list1 != nullptr) {
            node->next = list1;
            node = node->next;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            node->next = list2;
            node = node->next;
            list2 = list2->next;
        }

        return mergedList->next;


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
    vector<int> l1{1,2,4};
    vector<int> l2{1,3,5};

    ListNode* list1 = createLinkedListFomVec(l1);
    ListNode* list2 = createLinkedListFomVec(l2);

    Solution s;
    ListNode *res = s.mergeTwoLists(list1, list2);

    ListNode* rev = res;

    while(rev != nullptr) {
        cout << rev->val << endl;
        rev = rev->next;
    }


    return 0;
}