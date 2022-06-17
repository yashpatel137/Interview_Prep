vector<int> find(int arr[], int n , int x )
{
    vector<int> ans={-1,-1};
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int m=(s+e)/2;
        if(arr[m]==x)
        {
            while(arr[s]!=x)
            {
                s++;
            }
            while(arr[e]!=x)
            {
                e--;
            }
            ans[0]=s;
            ans[1]=e;
            return ans;
        }
        else if(arr[m]<x)
        {
            s=m+1;
        }
        else
        {
            e=m-1;
        }
    }
    return ans;
}

//Method 2
int getPosition(int arr[], int n, int x, string pos)
{
   int start = 0, end = n-1, position = -1;
   while(start<=end)
   {
       int mid = (start+end)/2;
       if(arr[mid] == x)
       {
           position = mid;
           if(pos=="first")
               end = mid-1;
           else
               start = mid+1;
       }
       else if(arr[mid]>x)
       {
           end = mid-1;
       }
       else
       {
           start = mid+1;
       }
   }
   return position;
}
vector<int> find(int arr[], int n , int x )
{
   int first = getPosition(arr,n,x,"first");
   int last = getPosition(arr,n,x,"last");
   
   return {first,last};
}
