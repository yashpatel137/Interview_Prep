class Solution{   
public:
    string smallestNumber(int S, int D){
        if(S>9*D)
        {
            return "-1";
        }
        string s="";
        for(int i=D-1;i>=0;i--)
        {
            if(S>9)
            {
                s="9"+s;
                S-=9;
            }
            else
            {
                if(i==0)
                {
                    s=to_string(S)+s;
                }
                else
                {
                    s=to_string(S-1)+s;
                    i--;
                    while(i>0)
                    {
                        s="0"+s;
                        i--;
                    }
                    s="1"+s;
                    break;
                }
            }
        }
        return s;
    }
};