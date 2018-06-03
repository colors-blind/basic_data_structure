/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    // set a temp node to swap left and right
    struct TreeNode* tempNode = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tempNode);
    return root;
}