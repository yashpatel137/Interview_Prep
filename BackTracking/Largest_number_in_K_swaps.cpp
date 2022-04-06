class Solution
{
    public:
    void solve(string str,string &maxi,int k,int id)
    {
        if(k==0)
        {
            return;
        }
        char c=str[id];
        for(int i=id+1;i<str.length();i++)
        {
            if(str[i]>c)
            {
                c=str[i];
            }
        }
        if(c!=str[id])
        {
            k--;
        }
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==c)
            {
                swap(str[id],str[i]);
                if(maxi<str)
                {
                    maxi=str;
                }
                solve(str,maxi,k,id+1);
                swap(str[id],str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string maxi=str;
        solve(str,maxi,k,0);
        return maxi;
    }
};