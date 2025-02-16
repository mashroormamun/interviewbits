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
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        ListNode *head, *ptr;
        
        if(list1->val > list2->val) {
            head = ptr = list2;
            list2 = list2->next;
        } else {
            head = ptr = list1;
            list1 = list1->next;
        }
        
        while(list1!=nullptr || list2!=nullptr) {
            if(list1 == nullptr) {
                ptr->next = list2;
                break;
            }
            
            if(list2 == nullptr) {
                ptr->next = list1;
                break;
            }
                
            if(list1->val < list2->val) {
                ptr->next = list1;
                ptr = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                ptr = list2;
                list2 = list2->next;
            }
        }
        
        return head;
    }
    
    ListNode* getLowestNode(vector<ListNode*>& lists) {
        int max=INT_MAX;
        ListNode* lowestNode = nullptr;
        
        for(int i=0;i<lists.size();i++) {
            if(lists[i] != nullptr) {
                if(lists[i]->val < max) {
                    lowestNode = lists[i];
                    max = lists[i]->val;
                }
            }
        }
        
        for(int i=0;i<lists.size();i++) {
            if(lists[i] != nullptr) {
                if(lists[i]->val == max) {
                    lists[i] = lists[i]->next;
                    break;
                }
            }
        }
        
        return lowestNode;
    }
        
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *head, *ptr, *temp;
        
//         head = ptr = getLowestNode(lists);
        
//         while(true) {
//             temp = getLowestNode(lists);
//             if(temp == nullptr) break;
            
//             ptr->next = temp;
//             ptr = ptr->next;
//         }
        
//         return head;
//     }
    
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.size()==0) return nullptr;
            
            vector<ListNode*> newlist = lists;
            
            while(newlist.size()>1) {
                vector<ListNode*> templist;
                    
                for(int i=0;i<newlist.size();i+=2) {
                    ListNode* a = newlist[i];
                    ListNode* b = nullptr;
                    
                    if((i+1) < newlist.size()) {
                        b=newlist[i+1];
                    }
                    
                    auto mergedlist = mergeTwoLists(a, b);
                    templist.push_back(mergedlist);
                }
                
                newlist=templist;
            }
        
        
            
    
            return newlist[0];
    }
};
