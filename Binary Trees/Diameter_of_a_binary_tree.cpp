class Solution {
  public:
    int solve(Node *node,int &ans)
    {
        if(node==NULL)
        {
            return 0;
        }
        int l=solve(node->left,ans);
        int r=solve(node->right,ans);
        int h=1+max(l,r);
        ans=max(ans,1+l+r);
        return h;
    }
    int diameter(Node* root) 
    {
        int dia=0;
        solve(root,dia);
        return dia;
    }
};