//Method 1
int getCount(Node *root, int l, int h)
{
    int count=0;
    if(!root)
    {
        return 0;
    }
    count+=getCount(root->left,l,h);
    count+=getCount(root->right,l,h);
    return (root->data>=l && root->data<=h)?count+1:count;
}

//Method 2
void countRange(Node*root , int l, int h, int &count)
{
   if(!root)
   {
       return;
   }
   if(root->data >=l && root->data <=h)
   {
       count++;
   }
   countRange(root->left,l,h,count);
   countRange(root->right,l,h,count);
}
int getCount(Node *root, int l, int h)
{
  int count = 0;
  countRange(root,l,h,count);
  return count;
}