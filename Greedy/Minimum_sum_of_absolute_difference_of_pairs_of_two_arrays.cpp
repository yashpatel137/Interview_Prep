long long int findMinSum(long long int a[],long long int b[], int n)
{
    sort(a, a+n);
    sort(b, b+n);
    long long int sum= 0 ;
    for (int i=0; i<n; i++)
    {
        sum = sum + abs(a[i]-b[i]);
    }
    return sum;
}