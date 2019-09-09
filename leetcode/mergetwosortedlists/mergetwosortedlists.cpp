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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* cur;
        ListNode* tmp;
        vector<int> v;
        
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        while (l1) {
            v.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v.push_back(l2->val);
            l2 = l2->next;          
        }
        sort(v.begin(),v.end());
        result = cur = new ListNode(0);
        for (auto n : v) {
            cur->next = new ListNode(n);
            cur = cur->next;
        }
        cur = result;
        result = result->next;
        delete cur; // Avoid memory leak
        return result;
        
    }
};
