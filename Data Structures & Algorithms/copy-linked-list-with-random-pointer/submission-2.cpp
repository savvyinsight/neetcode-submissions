/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        Node* curr = head;
        while(curr){
            Node* newnode = new Node(curr->val);
            newnode->next = curr->next;
            curr->next = newnode;
            curr = curr->next->next;
        }

        curr = head;
        while(curr){
            if(curr->random == nullptr){
                curr->next->random = nullptr;
                curr = curr->next->next;
                continue;
            }
            curr->next->random = curr->random->next;
            curr = curr->next->next; 
        }

        // A->nA->B->nB....
        // need to seperate, head list change to original
        curr = head;
        Node* p = curr->next;
        Node* newhead = p;
        while(curr){
            curr->next = curr->next->next;
            p->next = p->next?p->next->next:nullptr;
            curr = curr->next;
            p = p->next;
        }
        return newhead;
    }
};
