/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *curr = new ListNode(0);
        result = curr;
        unsigned int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry)
        {
            ListNode *node = new ListNode(0);
            
            if (l1 != NULL && l2 != NULL)
            {
                node->val = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
            }
            else if (l1 != NULL && l2 == NULL)
            {
                node->val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
            }
            else if (l1 == NULL && l2 != NULL)
            {
                node->val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
            }
            else
            {
                node->val = carry;
                carry = 0;
            }
            
            curr->next = node;
            curr = curr->next;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        
        return result->next;
    }
};