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
    void flattenLevel(Node* head) {
        Node* curNode = head;
        while (curNode != NULL) {
            Node* newElement = new Node(curNode->val, NULL, NULL, NULL);
            lastElement->next = newElement;
            newElement->prev = lastElement;
            lastElement = newElement;
            if (curNode->child != NULL) {
                flattenLevel(curNode->child);
            }
            curNode = curNode->next;
        }
    }
public:
    Node* flatten(Node* head) {
        flattenLevel(head);
        Node* newHead = dummyHead->next;
        if (newHead !=NULL) newHead->prev = NULL;
        return newHead;
    }
};