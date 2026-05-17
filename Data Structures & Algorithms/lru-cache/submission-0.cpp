class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node *prev;
            Node *next;

            Node(int key,int val){
                this->key=key;
                this->val=val;
            }
    };
    int cap;
    unordered_map<int, Node*> m;

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode){
        Node *temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next=temp;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode){
        Node *back = delNode->prev;
        Node *forw = delNode->next;

        back->next = forw;
        forw->prev = back;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node *resultNode = m[key];
            int ans = resultNode->val;
            m.erase(key);
            deleteNode(resultNode);
            addNode(resultNode);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node *temp = m[key];
            deleteNode(temp);
            m.erase(key);
        }

        if(m.size()==cap){
            Node *temp = tail->prev;
            int key = tail->prev->key;
            deleteNode(temp);
            m.erase(key);
        }

        Node *newNode = new Node(key,value);
        addNode(newNode);
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */