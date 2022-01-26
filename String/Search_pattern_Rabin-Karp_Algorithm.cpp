class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int> vec;
            int p=pat.size();
            int t=txt.size();
            int d=256;
            int q=73;
            int phash=0;
            int thash=0;
            int has=1;
            for(int i=0;i<p-1;i++)
            {
                has=(has*d)%q;
            }
            for(int i=0;i<p;i++)
            {
                phash=(d*phash+pat[i])%q;
                thash=(d*thash+txt[i])%q;
            }
            int j;
            for(int i=0;i<=t-p;i++)
            {
                if(phash==thash)
                {
                    for(j=0;j<p;j++)
                    {
                        if(txt[i+j]!=pat[j])
                        {
                            break;
                        }
                    }
                    if(j==p)
                    {
                        vec.push_back(i+1);
                    }
                }
                if(i<t-p)
                {
                    thash=(d*(thash-txt[i]*has)+txt[i+p])%q;
                    if(thash<0)
                    {
                        thash=thash+q;
                    }
                }
            }
            if(vec.empty())
            {
                vec.push_back(-1);
            }
            return vec;
        }
     
};