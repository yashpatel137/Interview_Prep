class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
        int prev=0,curr=0,start=0;
        for(int i=0;i<n;i++)
        {
            curr+=p[i].petrol-p[i].distance;
            if(curr<0)
            {
                prev+=curr;
                curr=0;
                start=i+1;
            }
        }
        return prev+curr>0?start:-1;
    }
};