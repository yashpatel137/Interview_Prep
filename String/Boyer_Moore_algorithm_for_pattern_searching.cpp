void badCharHeuristic(string pat,int m,int badChar[256])
{
    for(int i=0;i<256;i++)
    {
        badChar[i]=-1;
    }
    for(int i=0;i<m;i++)
    {
        badChar[(int)pat[i]]=i;
    }
}
bool searchPattern(string str, string pat)
{
    int m=pat.length();
    int n=str.length();
    int badChar[256];
    badCharHeuristic(pat,m,badChar);
    int s=0;
    while(s<=(n-m))
    {
        int j=m-1;
        while(j>=0 && pat[j]==str[s+j])
        {
            j--;
        }
        if(j<0)
        {
            cout << "pattern occurs at shift = " << s << endl;
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badchar[txt[s + j]]);
        }
    }
}