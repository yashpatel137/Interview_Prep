class Solution{
    public:
    int greater(int Y[], int n , int num)
    {
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(Y[mid]>num)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    long long countPairs(int X[], int Y[], int M, int N)
    {
       sort(X,X+M);
       sort(Y,Y+N);
       int zero=0,one=0,two=0,three=0,four=0;
       for(int i=0;i<N;i++)
       {
           if(Y[i]==0)
           {
               zero++;
           }
           if(Y[i]==1)
           {
               one++;
           }
           if(Y[i]==2)
           {
               two++;
           }
           if(Y[i]==3)
           {
               three++;
           }
           if(Y[i]==4)
           {
               four++;
           }
       }
       long long count=0;
       for(int i=0;i<M;i++)
       {
           if(X[i]==0)
           {
               continue;
           }
           else if(X[i]==1)
           {
               count+=zero;
           }
           else if(X[i]==2)
           {
               int ans=greater(Y,N,2);
               if(ans != -1)
               {
                   count+=N-ans;
               }
               count-=three;
               count-=four;
               count+=one+zero;
           }
           else
           {
               int ans=greater(Y,N,X[i]);
               if(ans != -1)
               {
                   count+=N-ans;
               }
               count+=one+zero;
               if(X[i]==3)
               {
                   count+=two;
               }
           }
           
       }
       return count;
    }
};
