int i = 0;
Node* solve(int pre[] , int n , int mxval)
{
   if(i == n || pre[i] > mxval)
   {
       return NULL;
   }
   
   Node* root = newNode(pre[i++]);
   
   root->left = solve(pre , n , root->data);
   root->right = solve(pre , n , mxval);
   return root;
}
Node* post_order(int pre[], int size)
{
   i = 0;
   return solve(pre , size , INT_MAX);
}