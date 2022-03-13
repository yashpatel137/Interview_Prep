class Solution
{
public:
    void inorder(Node *root, Node *&prev)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,prev);
        if(prev)
        {
            prev->next=root;
        }
        prev=root;
        inorder(root->right,prev);
    }
    void populateNext(Node *root)
    {
        Node *prev=NULL;
        inorder(root,prev);
    }
};