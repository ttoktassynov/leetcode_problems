/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //2->4->3
    //5->6->4
    //
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummyHeadResult = new ListNode();
        ListNode* cur = dummyHeadResult;
        
        
        while (l1 != NULL || l2 != NULL) {
            int val1 = (l1 == NULL) ? 0 : l1->val;
            int val2 = (l2 == NULL) ? 0 : l2->val;
            int sum = val1 + val2 + carry;
            cur->next = new ListNode(sum % 10);
            carry = sum /10;
            cur = cur->next;
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        if (carry > 0){
            cur->next = new ListNode(1);
        }
        return dummyHeadResult->next;
    }
    
   
};