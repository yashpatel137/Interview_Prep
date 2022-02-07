int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]==x)
        {
            return i;
        }
        i=i+max(1,(x-arr[i])/k);
    }
    return -1;
}   