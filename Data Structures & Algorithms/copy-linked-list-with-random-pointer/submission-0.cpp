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
        unordered_map<Node*, Node*> oldCopy;
        oldCopy[NULL] = NULL;

        Node *cur = head;
        while(cur!=NULL){
            Node* copy = new Node(cur->val);
            oldCopy[cur] = copy;
            cur = cur->next;
        }

        cur = head;
        while(cur!=NULL){
            Node *copy = oldCopy[cur];
            copy->next = oldCopy[cur->next];
            copy->random = oldCopy[cur->random];
            cur = cur->next;
        }
        return oldCopy[head];
    }
};
