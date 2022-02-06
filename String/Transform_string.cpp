class Solution
{
    public:
    int transform (string A, string B)
    {
        int n=A.length()-1;
        int m=B.length()-1;
        if(n!=m)
        {
            return -1;
        }
        int s1=0,s2=0;
        int cnt=0;
        while(n>=0 && m>=0)
        {
            s1+=A[n];
            s2+=B[m];
            n--;
            m--;
        }
        if(s1!=s2)
        {
            return -1;
        }
        n=A.length()-1;
        m=B.length()-1;
        while(n>=0 && m>=0)
        {
            if(A[n]==B[m])
            {
                n--;
                m--;
            }
            else
            {
                cnt++;
                n--;
            }
        }
        return cnt;
    }
};