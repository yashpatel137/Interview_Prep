class Solution{
    public:
    long long countWays(int n, int k)
    {
        int mod=1e9+7;
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return k;
        }
        long long diff=(k*(k-1))%mod,same=k%mod,total=(diff+same)%mod;
        for(int i=3;i<=n;i++)
        {
            same=diff;
            diff=(total*(k-1))%mod;
            total=(same+diff)%mod;
        }
        return total;
    }
};