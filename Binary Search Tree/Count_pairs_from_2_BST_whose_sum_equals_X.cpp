class Solution
{
public:
    void inorder(Node *root, vector<int> &vec)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> ans1,ans2;
        inorder(root1,ans1);
        inorder(root2,ans2);
        int i=0,j=ans2.size()-1,count=0;
        while(i<ans1.size() && j>=0)
        {
            int x1=ans1[i];
            int y=ans2[j];
            if(x1+y==x)
            {
                count++;
                i++;
                j--;
            }
            else if(x1+y<x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
    }
};