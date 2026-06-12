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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = nullptr;
        ListNode* m = head;
        ListNode* next = head->next;
        while(true){
            m->next = prev;
            if(!next) break;
            prev = m;
            m = next;
            next = next->next;
        }
        return m;
    }
};
