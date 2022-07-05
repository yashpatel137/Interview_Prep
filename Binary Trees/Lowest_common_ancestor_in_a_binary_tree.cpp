class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->data==n1 || root->data==n2)
        {
            return root;
        }
        Node *leftdata=lca(root->left,n1,n2);
        Node *rightdata=lca(root->right,n1,n2);
        if(leftdata!=NULL && rightdata!=NULL)
        {
            return root;
        }
        else if(leftdata!=NULL)
        {
            return leftdata;
        }
        else
        {
            return rightdata;
        }
    }
};

//Method 2 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,bool &f1,bool &f2) {
        if(!root) return NULL;
        else if(root==p){
            f1 = true;
            return root;
        }
        else if(root==q){
            f2 = true;
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q,f1,f2);
        TreeNode* right = lowestCommonAncestor(root->right,p,q,f1,f2);
        
        if(!left && !right) return NULL;
        else if(left && right) return root;
        else return left ? left:right;
    }
    bool findNode(TreeNode* root,TreeNode* target){
        if(root==NULL){
            return false;
        }
        if(root==target){
            return true;
        }
        return findNode(root->left,target)||findNode(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root || !p || !q){
            return NULL;
        }
        bool f1=false ,f2=false;
        TreeNode* temp = lowestCommonAncestor(root,p,q,f1,f2);
        if(!temp) return NULL;
        if(f1 && !f2 && !findNode(temp,q)) return NULL;
        if(!f1 && f2 && !findNode(temp,p)) return NULL;
        return temp;
    }
};
