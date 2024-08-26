class LRUCache {
public:
class node{
    public:
        int key;
        int val;
        node * next;
        node * prev;
        node(int key_,int val_)
        {
            key = key_;
            val = val_;
        }
    };
        node * head = new node(-1,-1);
        node * tail = new node(-1,-1);
        int cap ;
        unordered_map<int,node * > mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(node * t)
    {
        node * curr = head->next;
        t->next = curr;
        head->next = t;
        t->prev = head;
        curr->prev = t;
    }
    void deleteNode(node * t)
    {
        node * tprev = t->prev;
        node * tnext = t->next;
        tprev->next = tnext;
        tnext->prev = tprev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            node * nd = mp[key];
            mp.erase(key);
            deleteNode(nd);
            addNode(nd);
            mp[key]=head->next;
            return nd->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
             node * nd = mp[key];
             mp.erase(key);
            deleteNode(nd);
        }
        if(mp.size()==cap)
        {
            node * nd = tail->prev;
            mp.erase(nd->key);
            deleteNode(nd);
        }
            addNode(new node(key,value));
            mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */