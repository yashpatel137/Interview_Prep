// TC= O(n^2) SC= O(n)
class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> in(n),out(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    out[i]++;
                    in[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==n-1 && out[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
};

//TC= O(n) SC= O(1)
class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int cel=0;
        for(int i=1;i<n;i++)
        {
            if(M[cel][i]==1)
            {
                cel=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=cel && (M[cel][i]==1 || M[i][cel]==0))
            {
                return -1;
            }
        }
        return cel;
    }
};