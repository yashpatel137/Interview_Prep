class Solution{
public:
    int mod=1003;
    map<string,int> mp;
    int solve(string s,int i,int j,bool isTrue)
    {
        if(i>j)
        {
            return false;
        }
        if(i==j)
        {
            if(isTrue)
            {
                return s[i]=='T';
            }
            else
            {
                return s[i]=='F';
            }
        }
        string temp=to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(isTrue));
        if(mp.find(temp)!=mp.end())
        {
            return mp[temp];
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
            if(s[k]=='&')
            {
                if(isTrue)
                {
                    ans+=lt*rt;
                }
                else
                {
                    ans+=lt*rf+lf*rt+lf*rf;
                }
            }
            if(s[k]=='|')
            {
                if(isTrue)
                {
                    ans+=lt*rt+lf*rt+lt*rf;
                }
                else
                {
                    ans+=lf*rf;
                }
            }
            if(s[k]=='^')
            {
                if(isTrue)
                {
                    ans+=lf*rt+lt*rf;
                }
                else
                {
                    ans+=lt*rt+lf*rf;
                }
            }
        }
        return mp[temp]=ans%mod;
    }
    int countWays(int N, string S)
    {
        return solve(S,0,N-1,true);
    }
};