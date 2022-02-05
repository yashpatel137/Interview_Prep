class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(s.length()<p.length())
        {
            return "-1";
        }
        unordered_map<char,int> mp;
        for(auto &c:p)
        {
            mp[c]++;
        }
        int count=mp.size();
        int n=s.length();
        int start=-1;
        int len=INT_MAX;
        int i=0,j=0;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(mp.find(s[i])!=mp.end())
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                        {
                            count++;
                        }
                    }
                    i++;
                }
                if(len>j-i+2)
                {
                    len=j-i+2;
                    start=i-1;
                }
            }
            j++;
        }
        if(len==INT_MAX)
        {
            return "-1";
        }
        else
        {
            return s.substr(start,len);
        }
    }
};