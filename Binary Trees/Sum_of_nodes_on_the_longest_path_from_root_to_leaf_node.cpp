class Solution
{
public:
    void solve(Node *root,int level,int &maxlevel, int sum, int &maxsum)
    {
        if(root==NULL)
        {
            if(level>maxlevel)
            {
                maxlevel=level;
                maxsum=sum;
            }
            else if(level==maxlevel)
            {
                maxsum=max(sum,maxsum);
            }
            return;
        }
        sum+=root->data;
        solve(root->left,level+1,maxlevel,sum,maxsum);
        solve(root->right,level+1,maxlevel,sum,maxsum);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int maxsum=0,maxlevel=0;
        solve(root,0,maxlevel,0,maxsum);
        return maxsum;
    }
};