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
    // fast and slow pointer
    bool hasCycle_fast(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return false;
    }

    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while(curr){
            if(visited.find(curr) != visited.end()){
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
