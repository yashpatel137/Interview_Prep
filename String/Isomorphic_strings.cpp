class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n=str1.length();
        int m=str2.length();
        if(n!=m)
        {
            return false;
        }
        int cnt1[26]={0};
        int cnt2[26]={0};
        for(int i=i;i<n;i++)
        {
            cnt1[str1[i]-'a']++;
            cnt2[str2[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if((cnt1[str1[i]-'a'])!=(cnt2[str2[i]-'a']))
            {
                return false;
            }
        }
        return true;
    }
};

//Method 2
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s, string t)
    {
        int m1[256], m2[256];
        memset(m1, -1, sizeof(m1));
        memset(m2, -1, sizeof(m2));
        
        if(s.length() != t.length()) return false;
        
        for(int i = 0; i < s.length(); i++) {
            if(m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = m2[t[i]] = i;
        }
        
        return true;
    }
};