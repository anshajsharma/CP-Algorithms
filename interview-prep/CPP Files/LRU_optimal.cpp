
// Ques Link: https://practice.geeksforgeeks.org/problems/lru-cache/1#
class Node {
public:
    int key;
    int value;
    Node *pre;
    Node *next;
 
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};
 
class LRUCache {
private:
    map<int, Node*> M;
    int capacity, count;
    Node *head, *tail;
public:
 
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->next = NULL;
        count = 0;
    }
 
    void deleteNode(Node* node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
 
    void addToHead(Node *node)
    {
        node->next = head->next;
        node->next->pre = node;
        node->pre = head;
        head->next = node;
    }
 
    // This method works in O(1)
    int get(int key)
    {
        if (M.find(key)!=M.end()) {
            Node *node = M[key];
            int result = node->value;
            deleteNode(node);
            addToHead(node);
            return result;
        }
        return -1;
    }
 
    // This method works in O(1)
    void set(int key, int value)
    {
        if (M.find(key)!=M.end()) {
            Node *node = M[key];
            node->value = value;
            deleteNode(node);
            addToHead(node);
        }
        else {
            Node *node = new Node(key, value);
            M[key] = node;
            if (count < capacity) {
                count++;
                addToHead(node);
            }
            else {
                M.erase(tail->pre->key);
                deleteNode(tail->pre);
                addToHead(node);
            }
        }
    }
};
