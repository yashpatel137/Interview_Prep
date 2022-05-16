class Solution{
    public:
    int countSetBits(int n)
    {
        if(n==0)
        {
            return 0;
        }
        /* Formula for calc:
           solve(n)= pow(2,x-1)*x + (n-pow(2,x)+1) solve(n-pow(2,x))
           */
        int x=0;
        while((1<<x)<=n)
        {
            x++;
        }
        x=x-1;
        int bitsUptoX=(1<<(x-1))*x;
        int setMSBofRest=n-(1<<x)+1;
        int rest=n-(1<<x);
        return (bitsUptoX+setMSBofRest+countSetBits(rest));
    }
};