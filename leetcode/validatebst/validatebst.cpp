/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool isValidBSTHlpr(TreeNode* root, long int min, long int max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return (isValidBSTHlpr(root->left, min, root->val) &&
                isValidBSTHlpr(root->right, root->val, max));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHlpr(root, numeric_limits<long int>::lowest(), numeric_limits<long int>::max());
    }
};
