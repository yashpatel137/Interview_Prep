class Solution {
  public:
    string longestPalin (string S) 
    {
        int l,h,start=0,end=1;
        int n=S.size();
        for(int i=1;i<n;i++)
        {
            l=i-1;
            h=i;
            while(l>=0 && h<n && S[l]==S[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
            l=i-1;
            h=i+1;
            while(l>=0 && h<n && S[l]==S[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
        }
        return S.substr(start,end);
    }
};