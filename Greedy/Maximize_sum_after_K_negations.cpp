class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i=0;
        long long ans=0;
        while(i<n && a[i]<0 && k)
        {
            a[i]*=-1;
            i+=1;
            k-=1;
        }
        if(i<n && a[i]!=0 && k%2!=0)
        {
            a[i]*=-1;
        }
        if(i==n && k%2!=0)
        {
            a[n-1]*=-1;
        }
        for(i=0;i<n;i++)
        {
            ans+=a[i];
        }
        return ans;
    }
};