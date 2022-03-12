int minValue(struct Node *root) 
{
    if(!root)
    {
        return -1;
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}