//Method recursion
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inorder(Node *root, vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int> inOrder(Node* root) 
    {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

//Method iterative
class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) 
    {
        vector<int> ans;
        stack<Node*> st;
        Node *temp=root;
        while(!st.empty()||temp!=NULL)
        {
            if(temp!=NULL)
            {
                st.push(temp);
                temp=temp->left;
            }
            else
            {
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                temp=temp->right;
            }
        }
        return ans;
    }
};