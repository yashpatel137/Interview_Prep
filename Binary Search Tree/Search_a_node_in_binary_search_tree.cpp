bool search(struct Node* root, int x) 
{
    if(!root)
    {
        return false;
    }
    if(root->data==x)
    {
        return true;
    }
    else if(root->data < x)
    {
        return search(root->right,x);
    }
    else
    {
        return search(root->left,x);
    }
}