class Solution
{
    public:
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    
    bool isSumTree(Node* root)
    {
        int ls,rs;
        if(root==NULL || isLeaf(root))
        {
            return true;
        }
        if(isSumTree(root->left) && isSumTree(root->right))
        {
            if(root->left==NULL)
            {
                ls=0;
            }
            else if(isLeaf(root->left))
            {
                ls=root->left->data;
            }
            else
            {
                ls=2*(root->left->data);
            }
            if(root->right==NULL)
            {
                rs=0;
            }
            else if(isLeaf(root->right))
            {
                rs=root->right->data;
            }
            else
            {
                rs=2*(root->right->data);
            }
            return (root->data==ls+rs);
        }
        return false;
    }
};