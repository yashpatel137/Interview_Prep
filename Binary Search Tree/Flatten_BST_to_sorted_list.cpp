void inorder(node* curr, node*& prev)
{
    if (curr == NULL)
        return;
    inorder(curr->left, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    inorder(curr->right, prev);
}
node* flatten(node* parent)
{
    node* dummy = new node(-1);
    node* prev = dummy;
    inorder(parent, prev);
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
    delete dummy;
    return ret;
}