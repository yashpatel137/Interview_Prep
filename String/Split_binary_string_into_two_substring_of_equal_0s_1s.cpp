int maxSubstring(string s, int n)
{
    int cnt0=0,cnt1=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;        
        }
        if(cnt0==cnt1)
        {
            cnt++;
        }
    }
    if(cnt0!=cnt1)
    {
        return -1;
    }
    return cnt;
}