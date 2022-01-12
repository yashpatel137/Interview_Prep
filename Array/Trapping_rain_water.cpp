//Method 1
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        vector<int> pre(n,0),suf(n,0);
        pre[0]=arr[0];
        suf[n-1]=arr[n-1];
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            pre[i]=max(arr[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=max(arr[i],suf[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            int temp=min(pre[i],suf[i]);
            int add=temp-arr[i];
            if(add>=0)
            {
                ans+=add;
            }
        }
        return ans;
    }
};

//Method 2
class Solution{
    public:
    long long trappingWater(int arr[], int n){
        long long ans=0;
        int l=0,r=n-1;
        int leftmax=0;
        int rightmax=0;
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                if(leftmax<=arr[l])
                {
                    leftmax=arr[l];
                }
                else
                {
                    ans+=leftmax-arr[l];
                }
                l++;
            }
            else
            {
                if(rightmax<=arr[r])
                {
                    rightmax=arr[r];
                }
                else
                {
                    ans+=rightmax-arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};