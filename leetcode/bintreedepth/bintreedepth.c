/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    int max_depth = 1;
    int depth_l = 0, depth_r = 0;
    if (root == NULL)
        return 0;

    // traverse tree
    if (root->left)
        depth_l = maxDepth(root->left);
    
    if (root->right)
        depth_r = maxDepth(root->right);
    
    max_depth += depth_l > depth_r ? depth_l : depth_r;
    return max_depth;
}
