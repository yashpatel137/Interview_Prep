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