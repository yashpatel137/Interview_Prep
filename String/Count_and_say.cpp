class Solution {
public:
    string countAndSay(int n) 
    {
        string s="1";
        for(int i=2;i<=n;i++)
        {
            string ans="";
            int count=1,j=1;
            while(j<s.length())
            {
                if(s[j]==s[j-1])
                {
                    count++;
                }
                else
                {
                    ans+=to_string(count)+s[j-1];
                    count=1;
                }
                j++;
            }
            ans+=to_string(count)+s[j-1];
            s=ans;
        }
        return s;
    }
};