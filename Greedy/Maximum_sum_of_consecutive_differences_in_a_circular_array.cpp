long long int maxSum(int arr[], int n)
{
    long long int sum=0;
    int i=0,j=n-1;
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        sum+=abs(arr[i]-arr[j--]);
    }
    return sum;
}