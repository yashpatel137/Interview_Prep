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