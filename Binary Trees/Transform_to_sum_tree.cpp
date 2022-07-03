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

//Method 2
int solve(Node *node){
        if(!node)  return 0;
        
        int temp=node->data;
        node->data=solve(node->right)+solve(node->left);
        
        return temp+node->data;
    }
    void toSumTree(Node *node)
    {
      solve(node);
    }
