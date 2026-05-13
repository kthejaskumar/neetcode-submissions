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
        ListNode* cur = new ListNode(0);
        ListNode* dummy = cur;
        while(list1 && list2){
            if(list1->val<=list2->val){
                cur->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else{
                cur->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            cur = cur->next;
        }

        if(list1){
            cur->next=list1;
        }
        else{
            cur->next=list2;
        }

        return dummy->next;
    }
};
