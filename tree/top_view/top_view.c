//      3
//    /   \
//   5     2
//  / \   / \
// 1   4 6   7
//  \       /
//   9     8

// 对左子树，逆序打印出来左子树的左节点
// 对右子树，顺序打印出来右子树的右节点
// from https://www.hackerrank.com/challenges/tree-top-view/problem

void top_view(struct node * root) {

    int array[100] = {0};
    int count = 0;
    struct node * temp;

    if (root) {
        if (root->left) {
            temp = root;
            while (temp->left) {
                // printf("%d ", temp->left->data);
                array[count] = temp->left->data;
                count++;
                temp = temp->left;
            }
        }

        for (int i = count - 1; i >= 0; i--) {
            printf("%d ", array[i]);
        }

        array[count] = root->data;
        printf("%d ", array[count]);

        if (root->right) {
            temp = root;
            while (temp->right) {
                printf("%d ", temp->right->data);
                array[count] = temp->left->data;
                count++;
                temp = temp->right;
            }
        }
    } else {
        return ;
    }
}
