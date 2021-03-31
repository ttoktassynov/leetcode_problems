/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
class Solution {
    Node* dummyHead = new Node(0, NULL, NULL, NULL);
    Node* lastElement = dummyHead;
    void append(Node* node) {
        lastElement->next = node;
        node->prev = lastElement;
        lastElement = node;
    }
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }
        stack<Node*> stack;
        stack.push(head);
        while(!stack.empty()) {
            Node * curNode = stack.top();
            stack.pop();
            Node* nextNode = curNode->next;
            append(curNode);
            if (nextNode != NULL) {
                stack.push(nextNode);
            }
            if (curNode->child != NULL) {
                stack.push(curNode->child);
            }
    
            curNode->child = NULL;
        }
        dummyHead->next->prev = NULL;
        return dummyHead->next;
    }
};