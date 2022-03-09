class Solution{
  public:
    unordered_map<Node*,int>mp;
    int getMaxSum(Node *root) 
    {
        if(root==NULL)
        {
            return 0;

        }
        if(mp[root])
        {
            return mp[root];
        }
        int sum=root->data;
        if(root->left)
        {
            sum+=getMaxSum(root->left->left);
            sum+=getMaxSum(root->left->right);
        }
        if(root->right)
        {
            sum+=getMaxSum(root->right->left);
            sum+=getMaxSum(root->right->right);
        }
        int nonode=0;
        nonode+=getMaxSum(root->left);
        nonode+=getMaxSum(root->right);
        int ans=max(sum,nonode);
        mp[root]=ans;
        return mp[root];
    }
};