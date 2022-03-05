#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *construct(string s,int &i)
{
    if(s.size()==0 || i>=s.size())
    {
        return NULL;
    }
    int num=0;
    while(i<s.size() && s[i]!='(' && s[i]!=')')
    {
        int numnew=(int)(s[i]-'0');
        num=num*10+numnew;
        i=i+1;
    }
    Node *root=new Node(num);
    if(i<s.size() && s[i]=='(')
    {
        i+=1;
        root->left=construct(s,i);
    }
    if(i<s.size() && s[i]==')')
    {
        i+=1;
        return root;
    }
    if(i<s.size() && s[i]=='(')
    {
        i+=1;
        root->right=construct(s,i);
    }
    if(i<s.size() && s[i]==')')
    {
        i+=1;
    }
    return root;

}

void preorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    string s="4(2(3)(1))(6(5))";
    int i=0;
    Node *root=construct(s,i);
    preorder(root);
    return 0;
}