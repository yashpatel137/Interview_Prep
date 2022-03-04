class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool check(Node *root, int &h)
    {
        int lh=0,rh=0;
        int lb=0,rb=0;
        if(root==NULL)
        {
            h=0;
            return true;
        }
        lb=check(root->left,lh);
        rb=check(root->right,rh);
        h=(lh>rh?lh:rh)+1;
        if(abs(lh-rh)>1)
        {
            return false;
        }
        return lb&&rb;
    }
    bool isBalanced(Node *root)
    {
        int h=0;
        return check(root,h);
    }
};