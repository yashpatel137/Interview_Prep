class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int n=S.length();
        int count=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(S[i]==']')
            {
                count+=1;
            }
            else
            {
                if(count>0)
                {
                    ans+=count;
                }
                count-=1;
            }
        }
        return ans;
    }
};