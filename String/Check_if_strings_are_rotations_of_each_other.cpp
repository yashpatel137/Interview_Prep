class Solution
{
    public:
    bool areRotations(string s1,string s2)
    {
        queue<char> q1,q2;
        int n=s1.length();
        int m=s2.length();
        for(int i=0;i<n;i++)
        {
            q1.push(s1[i]);
        }
        for(int i=0;i<m;i++)
        {
            q2.push(s2[i]);
        }
        while(m--)
        {
            char ch=q2.front();
            q2.pop();
            q2.push(ch);
            if(q2==q1)
            {
                return true;
            }
        }
        return false;
    }
};