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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
   
        if(ptr1->next == nullptr) return false;
        
        ptr1 = ptr1->next;

        if(ptr1->next != nullptr) {
            ptr2 = ptr1->next;
        } else {
            return false;
        }

        

        while(ptr2 != nullptr ) {
            if(ptr1 == ptr2) return true;

            ptr1 = ptr1->next;

            if(ptr2->next == nullptr) {
                return false;
            } else if (ptr2->next->next == nullptr) {
                return false;
            }

            ptr2 = ptr2->next->next;
        }

        return false;
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
    vector<int> l1{1};

    ListNode* list1 = createLinkedListFomVec(l1);

    // list1->next->next->next = list1;

    

    Solution s;
    bool res = s.hasCycle(list1);

    cout << res << endl;

    // ListNode* rev = list1;

    // while(rev != nullptr) {
    //     cout << rev->val << endl;
    //     rev = rev->next;
    // }


    return 0;
}