void inOrder(node *root) {
    if (root) {
        if (root->left) {
            inOrder(root->left);
        }
        // print root in middle
        printf("%d ", root->data);
        if (root->right) {
            inOrder(root->right);
        }
    } else {
        return;
    }

}