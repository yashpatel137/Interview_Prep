//Method 1
class Solution
{
    public:
    void inorder(Node *root,vector<int> &ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        if(!root1)
        {
            inorder(root2,ans);
            return ans;
        }
        else if(!root2)
        {
            inorder(root1,ans);
            return ans;
        }
        else
        {
            inorder(root2,ans);
            inorder(root1,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//Method 2
class Solution
{
    public:
    void helper(stack<Node*> &s,Node *root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        stack<Node*> s1,s2;
        helper(s1,root1);
        helper(s2,root2);
        while(!s1.empty() || !s2.empty()){
            int a=(s1.size())?s1.top()->data:INT_MAX;
            int b=(s2.size())?s2.top()->data:INT_MAX;
            if(a<=b){
               Node *temp=s1.top();
               s1.pop();
               ans.push_back(temp->data);
               helper(s1,temp->right);
            }
            else{
                Node *temp=s2.top();
               s2.pop();
               ans.push_back(temp->data);
               helper(s2,temp->right);
                
            }
        }
        return ans;
    }
};

//Method 3
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if( root1 == NULL && root2==NULL){
            return NULL;
        }
        TreeNode* temp = new TreeNode();
        if(root1!=NULL && root2!=NULL){
            temp->val=root1->val+root2->val;
            temp->left = mergeTrees(root1->left,root2->left);
            temp->right = mergeTrees(root1->right,root2->right);
        }else if(root1!=NULL){
            temp=root1;
        }else{
            temp=root2;
        }
        return temp;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        //store the leaves of every node

        unordered_map<int,TreeNode*> mp;
        
        //store the current min and current max nodes in the current tree
        unordered_map<TreeNode*,pair<int,int>> mini;
        for(int i=0;i<trees.size();i++)
        {
            pair<int,int> ans={trees[i]->val,trees[i]->val};
            if(trees[i]->left)
            {
                
                mp[trees[i]->left->val]={trees[i]};
                ans.first=trees[i]->left->val;
            }
            if(trees[i]->right)
            {
                mp[trees[i]->right->val]=trees[i];
                ans.second=trees[i]->right->val;
            }
            mini[trees[i]]=ans;
        }
        
        //store the number of merging operations we will be doing
        int count=0;
        int rootCount=0;
        TreeNode* root=NULL;
        //now for every node get the root
        for(int i=0;i<trees.size();i++)
        {
            
            //if the current tree can be merged into some other tree
            if(mp.find(trees[i]->val)!=mp.end())
            {
                count++;
                //merge them
                TreeNode* parent=mp[trees[i]->val];
                if(trees[i]->val < parent->val)
                {
                    //left child 
                    
                    //if the maximum of the current sub tree is greater than the parent value 
                    //then return NULL
                    if(parent->val <= mini[trees[i]].second)
                        return NULL;
                    //change the minimum value of the parent tree to the current min value of the tree
                    mini[parent].first=mini[trees[i]].first;
                    //merge the trees
                    parent->left=trees[i];
                }
                else  if(trees[i]->val > parent->val)
                {
                    //right child
                    
                    //if the minimum of the current tree is lesser than the parent value
                    //we cannot merge 
                    //so return NULL
                    if(parent->val >= mini[trees[i]].first)
                        return NULL;
                    
                    //change the parent tree maximum to the current tree maximum
                    mini[parent].second=mini[trees[i]].second;
                    //merge the trees
                    parent->right=trees[i];
                }
                //erase the current tree value
                mp.erase(trees[i]->val);
            }
            else{
                //it has no other tree to merge 
                //it is the root node we should return 
                if(rootCount==1)
                    return NULL;
                else 
                {
                    rootCount++;
                    root=trees[i];
                }
            }
        }
        //if we are not able to merge all trees return NULL
        if(count!=trees.size()-1)
            return NULL;
        return root;
        
    }
};
