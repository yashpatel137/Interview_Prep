class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->data==n1 || root->data==n2)
        {
            return root;
        }
        Node *leftdata=lca(root->left,n1,n2);
        Node *rightdata=lca(root->right,n1,n2);
        if(leftdata!=NULL && rightdata!=NULL)
        {
            return root;
        }
        else if(leftdata!=NULL)
        {
            return leftdata;
        }
        else
        {
            return rightdata;
        }
    }
};