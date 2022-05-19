//Method 1 TLE
class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long quot=0;
        int sign=((dividend<0)^(divisor<0))?-1:1;
        dividend=abs(dividend);
        divisor=abs(divisor);
        while(dividend>=divisor)
        {
            dividend-=divisor;
            quot++;
        }
        return sign*quot;
    }
};

//Method 2 No TLE
class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        long long quot=0;
        int sign=((dividend<0)^(divisor<0))?-1:1;
        long long a=abs(dividend);
        long long b=abs(divisor);
        while((a-b)>=0)
        {
            int x=0;
            while(a-(b<<1<<x)>=0)
            {
                x++;
            }
            quot+=1<<x;
            a-=b<<x;
        }
        return sign*quot;
    }
};