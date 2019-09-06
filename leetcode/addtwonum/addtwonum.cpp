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
        ListNode *node_head = NULL;
        ListNode *node = node_head;
        bool carry = false;
        
        while (l1 || l2) {
            int num1 = 0, num2 = 0;
            if (l1) {
                num1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                num2 = l2->val;
                l2 = l2->next;
            }
            int sum = num1 + num2;
            if (carry) {
                sum++;
                carry = false;
            }
            if (sum >= 10) {
                carry = true;
                sum -= 10;
            }
            if (node_head == NULL) {
                node_head = new ListNode(sum);
                node = node_head;
            } else {
                node->next = new ListNode(sum);
                node = node->next;
            }
        }
        
        if (carry) {
            node->next = new ListNode(1);
        }

        return node_head;
    }
};
