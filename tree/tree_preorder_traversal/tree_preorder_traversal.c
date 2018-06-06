void preOrder(node *root) {
    if (root == NULL) {
        return;
    }
    // print root data first
    printf("%d ", root->data);
    if (root->left) {
        preOrder(root->left);
    }
    if (root->right) {
        preOrder(root->right);
    }
}