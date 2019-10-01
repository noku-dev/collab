/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBSTVal(struct TreeNode* root, bool lnotset, int lower, bool unotset, int upper) {
    bool valid = true;
    // printf("root->val %d, lower %d, upper %d\n", root->val, lower, upper);
    if ((lnotset || (root->val) > lower) && (unotset || (root->val) < upper)) {
        if (root->left)
            valid = isValidBSTVal(root->left, lnotset, lower, false, root->val);
        if (valid == false)
            return valid;
        if (root->right)
            valid = isValidBSTVal(root->right, false, root->val, unotset, upper);
    } else
        valid = false;
    return valid;
}

bool isValidBST(struct TreeNode* root){
    bool valid = true;
    if (root == NULL)
        return true;
    
    if (root->left)
        valid = isValidBSTVal(root->left, true, 0, false, root->val);

    if (valid == false)
        return valid;

    if (root->right)
        valid = isValidBSTVal(root->right, false, root->val, true, 0);
    
    return valid;
}
