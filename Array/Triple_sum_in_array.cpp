//Method 1
class Solution{
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        for(int i=0;i<n-2;i++)
        {
            unordered_set<int> s;
            int sum=X-A[i];
            for(int j=i+1;j<n;j++)
            {
                if(s.find(sum-A[j])!=s.end())
                {
                    return true;
                }
                s.insert(A[j]);
            }
        }
        return false;
    }

};

//Method 2

class Solution{
    public:
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        int ans=0;
        int l,h;
        for(int i=0;i<n-1;i++)
        {
            l=i+1;
            h=n-1;
            while(l<h)
            {
                ans=A[i]+A[l]+A[h];
                if(ans==X)
                {
                    return true;
                }
                else if(ans<X)
                {
                    l++;
                }
                else
                {
                    h--;
                }
            }
        }
        return false;
    }

};