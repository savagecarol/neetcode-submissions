class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {

    int cap;
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

public:

    LRUCache(int capacity) {
        this->capacity = capacity;
        cap = 0;
        head = new Node(-1, -1); 
        tail = new Node(-1, -1);  
        head->next = tail;
        tail->prev = head;   
    }
    

    void insert(Node* node){
        Node* nextEle = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextEle;
        nextEle->prev = node;
    }

    void remove(Node* curr){
        Node* prevEle = curr->prev;
        Node* nextEle = curr->next;

        prevEle->next = nextEle;
        nextEle->prev = prevEle;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];

        remove(node);
        insert(node);

        return node->value;
    }

    
       void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);

            return;
        }

        if(mp.size() == capacity){
            Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);
    }
};
