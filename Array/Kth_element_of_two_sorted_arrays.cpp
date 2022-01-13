class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0,ans=0;
        while(i<n && j<m)
        {
            if(arr1[i]<arr2[j])
            {
                ans=arr1[i];
                i++;
                k--;
            }
            else
            {
                ans=arr2[j];
                j++;
                k--;
            }
            if(k==0)
            {
                return ans;
            }
        }
        while(i<n && k!=0)
        {
            ans=arr1[i++];
            k--;
        }
        while(j<m && k!=0)
        {
            ans=arr2[j++];
            k--;
        }
        return ans;
    }
};