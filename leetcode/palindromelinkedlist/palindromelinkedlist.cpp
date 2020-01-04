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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        int size{0};
        if (head == nullptr) return true;
        ListNode* tmp = head;
        while (tmp) {
            st.push(tmp->val);
            tmp = tmp->next;
            size++;
        }
        tmp = head;
        for (int i = 0; i < size/2; i++) {
            if (tmp->val != st.top()) return false;
            tmp = tmp->next;
            st.pop();
        }
        return true;
    }
};
