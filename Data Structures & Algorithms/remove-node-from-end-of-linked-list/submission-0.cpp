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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            cnt++;
            curr = curr->next;
        }

        int removeIndex = cnt-n;
        if(removeIndex == 0){
            return head->next;
        }

        curr = head;
        for(int i = 0;i<cnt-1;i++){
            if(removeIndex == i+1){
                curr->next = curr->next->next;
                break;
            }
            curr=curr->next;
        }
        return head;
    }
};
