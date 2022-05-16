class Solution{
    public:
    bool isPowerofTwo(long long n)
    {
        if(n==0)
        {
            return false;
        }
        int count=0;
        while(n>0)
        {
            if(n&1==1)
            {
                count++;
            }
            n=n>>1;
        }
        return (count==1)?true:false;
    }
};