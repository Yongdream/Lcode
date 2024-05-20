/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start


class LRUCache {
public:
    // 为了o(1)拿到key--哈希表
    // o(1)内插入删除--双向链表

    struct Node {
        int key, val;
        Node* prev, * next; //双向

        // 构造函数
        Node() : key(0), val(0), prev(nullptr), next(nullptr) {};
        Node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {};
    };

    unordered_map<int, Node*> mp;
    Node* head, * tail; // 哨兵节点
    int capacity, size; // 容量

    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new Node();
        tail = new Node();

        head->next = tail;  // 头节点 构成双向链表
        tail->next = head;  
    }
    
    // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* node = mp[key];
        removeNode(node);
        addNodeToHead(node);
        return node->val;
    }
    
    // 如果关键字 key 已经存在，则变更其数据值 value ；
    // 如果不存在，则向缓存中插入该组 key-value
    // 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNodeToHead(node);
        }
        else
        {
            if (size == capacity) { // 超出容量
                Node* removed = tail->prev;
                mp.erase(removed->key);     // 哈希表也删除
                removeNode(removed);        // 列表中删除
                size--;
            }
            Node* node = new Node(key, value);
            addNodeToHead(node);
            mp[key] = node;
            size++;
        }
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node* node) {
        // 设置当前节点的prev next指针
        // 以 head<->10 插入12为例
        node->prev = head;
        node->next = head->next;    // head<-12->10

        head->next->prev = node;
        head->next = node;          // head<->12<->10
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

