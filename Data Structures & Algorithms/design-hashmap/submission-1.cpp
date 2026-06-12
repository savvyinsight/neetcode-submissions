struct ListNode {
    int key, val;
    ListNode* next;
    ListNode() : key(0), val(0), next(nullptr) {}
    ListNode(int key) : key(key), val(0), next(nullptr) {}
    ListNode(int key, int val) : key(key), val(val), next(nullptr) {}
};

class MyHashMap {
private:
    vector<ListNode*> map;
    const int SIZE = 10000;
    
    int hash(int key) {
        return key % SIZE;
    }
    
public:
    MyHashMap() {
        map.resize(SIZE, nullptr);
    }
    
    ~MyHashMap() {
        for(auto& head : map) {
            while(head) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void put(int key, int value) {
        int index = hash(key);
        
        // Handle empty bucket
        if(!map[index]) {
            map[index] = new ListNode(key, value);
            return;
        }
        
        // Search for existing key
        ListNode* curr = map[index];
        ListNode* prev = nullptr;
        
        while(curr) {
            if(curr->key == key) {
                curr->val = value;  // Update existing key
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        
        // Key doesn't exist - add new node at end
        prev->next = new ListNode(key, value);
    }
    
    int get(int key) {
        int index = hash(key);
        if(!map[index]) {
            return -1;
        }
        
        ListNode* curr = map[index];
        while(curr) {
            if(curr->key == key) {
                return curr->val;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        if(!map[index]) {
            return;
        }
        
        ListNode* curr = map[index];
        ListNode* prev = nullptr;
        
        while(curr) {
            if(curr->key == key) {
                if(prev) {
                    prev->next = curr->next;
                } else {
                    map[index] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};