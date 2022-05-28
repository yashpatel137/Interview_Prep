
int LISS(Node *root)
{
    if(!root)
    {
        return 0;
    }
    if(!root->left and !root->right)
    {
        return 1;
    }
    int take=0,nottake=0;
    nottake+=LISS(root->left)+LISS(root->right);
    take=1;
    if(root->left)
    {
        take+=LISS(root->left->left)+LISS(root->left->right);
    }
    if(root->right)
    {
        take+=LISS(root->right->left)+LISS(root->right->right);
    }
    return max(take,nottake);
}