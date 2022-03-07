class Solution{
  public:
    set<int> s;
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    void solve(Node *root, int level)
    {
        if(!root)
        {
            return;
        }
        if(isLeaf(root))
        {
            s.insert(level);
        }
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    bool check(Node *root)
    {
        solve(root,0);
        if(s.size()!=1)
        {
            return false;
        }
        return true;
    }
};