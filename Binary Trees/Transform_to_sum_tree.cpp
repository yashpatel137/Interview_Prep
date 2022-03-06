class Solution {
  public:
    int solve(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int templ=solve(root->left);
        int tempr=solve(root->right);
        int x=root->data;
        root->data=templ+tempr;
        return templ+tempr+x;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};