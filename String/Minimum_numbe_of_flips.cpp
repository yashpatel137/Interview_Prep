int minFlips (string S)
{
    //101010... or
    //010101...
    int n=S.length();
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0 && S[i]=='1')
        {
            count++;
        }
        if(i%2==1 && S[i]=='0')
        {
            count++;
        }
    }
    return min(count,n-count);
}