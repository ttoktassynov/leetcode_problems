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
    void dfs(Node* node) {
        if (node == NULL) {
            return;
        }
        Node* next = node->next;
        append(node);
        dfs(node->child);
        node->child = NULL;
        dfs(next);
    }
public:
    Node* flatten(Node* head) {
        dfs(head);
        if (dummyHead->next != NULL) dummyHead->next->prev = NULL;
        return dummyHead->next;
    }
};