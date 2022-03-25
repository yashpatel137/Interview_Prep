class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long int sum=0,mod=pow(10,9)+7;
        for(int i=0;i<n;i++)
        {
            sum+=(long long int)a[i]*i;
        }
        return int(sum%mod);
    }
};