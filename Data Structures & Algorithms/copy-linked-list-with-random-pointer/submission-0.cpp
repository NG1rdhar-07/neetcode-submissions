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
        Node *temp = head;

        while(temp != nullptr){
            Node *nd = new Node(temp -> val);
            nd -> next = temp -> next;
            temp -> next = nd;

            temp = temp -> next -> next;
        }

        temp = head;

        while(temp != nullptr){
            Node *nd = temp -> next;

            if(temp -> random != nullptr)
            nd -> random = temp -> random -> next;
            // nd -> random = temp -> random; WRONG
            
            else
            nd -> random = nullptr;

            temp = temp -> next -> next;
        }

        Node *dmy = new Node(-1);
        Node *res = dmy;
        temp = head;

        while(temp != nullptr){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next; // pointing temp towards original, instead of dummy !!
            
            res = res -> next;
            temp = temp -> next; //move temp to next location !!
        }

        return dmy -> next;
    }
};
