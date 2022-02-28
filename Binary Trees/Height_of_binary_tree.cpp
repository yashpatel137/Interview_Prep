class Solution{
    public:
    int height(struct Node* node)
    {
        if(node==NULL)
        {
            return 0;
        }
        int l=height(node->left);
        int r=height(node->right);
        int h=1+max(l,r);
        return h;
    }
};