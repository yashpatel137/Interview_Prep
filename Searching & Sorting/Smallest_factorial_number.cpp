class Solution
{
    public:
        bool check(int num,int n)
        {
            int tmp=num,cnt=0,f=5;
            while(f<=tmp)
            {
                cnt+=tmp/f;
                f*=5;
            }
            return cnt>=n;
        }
        int findNum(int n)
        {
            if(n==1)
            {
                return 5;
            }
            int lo=0;
            int hi=5*n;
            while(lo<hi)
            {
                int mid = (lo+hi)>>1;
                if(check(mid,n))
                {
                    hi=mid;
                }
                else
                {
                    lo=mid+1;
                }
            }
            return lo;
        }
};