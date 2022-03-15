class Solution {
  public:
    int count=0,ans=-1;
    void solve(Node *root, int K)
    {
        if(!root)
        {
            return;
        }
        solve(root->left,K);
        count++;
        if(count==K)
        {
            ans=root->data;
            return;
        }
        else
        {   
            solve(root->right,K);
        }
    }
    int KthSmallestElement(Node *root, int K) 
    {
        solve(root,K);
        return ans;
    }
};