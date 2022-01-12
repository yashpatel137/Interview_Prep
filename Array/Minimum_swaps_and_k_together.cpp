class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int gd=0,bd=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=k)
            {
                gd++;
            }
        }
        for(int i=0;i<gd;i++)
        {
            if(arr[i]>k)
            {
                bd++;
            }
        }
        int ans=bd;
        int i=0,j=gd;
        while(j<n)
        {
            if(arr[i]>k)
            {
                --bd;
            }
            if(arr[j]>k)
            {
                ++bd;
            }
            ans=min(ans,bd);
            i++;
            j++;
        }
        return ans;
    }
};