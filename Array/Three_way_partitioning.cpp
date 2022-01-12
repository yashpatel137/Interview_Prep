class Solution{   
public:
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n=arr.size();
        int l=0,m=0,r=n-1;
        while(m<=r)
        {
            if(arr[m]<a)
            {
                swap(arr[m],arr[l]);
                m++;
                l++;
            }
            else if(arr[m]>=a && arr[m]<=b)
            {
                m++;
            }
            else
            {
                swap(arr[m],arr[r]);
                r--;
            }
        }
    }
};