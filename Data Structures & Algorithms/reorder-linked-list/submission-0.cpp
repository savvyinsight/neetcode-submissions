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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        // find the middle
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        // separation
        slow->next = nullptr;
        // reverse second part
        ListNode* rev = reverseList(mid);

        // reorder or merge
        ListNode* p = head;
        while(rev!=nullptr){
            ListNode* t1 = p->next;
            ListNode* t2 = rev->next;
            p->next = rev;
            rev->next = t1;

            p = t1;
            rev = t2;
        }
    }

    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};
