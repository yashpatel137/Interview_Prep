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

//Method 2
class Solution{
    public:
    int flag=1;
    int check(Node *root)
    {
        int l=0,r=0;
        if(root==NULL)
        {
            return 0;
        }
        l=check(root->left);
        r=check(root->right);
        if(abs(l-r)>1)
        {
            flag=0;
        }
        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        flag=1;
        check(root);
        return flag;
    }
};