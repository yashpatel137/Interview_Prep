class Solution{
    public:
    static int countSetBit(int n)
    {
        int cnt=0;
        while(n!=0)
        {
            int rsbm=n & -n;
            n-=rsbm;
            cnt++;
        }
        return cnt;
    }
    static bool cmpBit(int x,int y)
    {
        int cnt1=countSetBit(x);
        int cnt2=countSetBit(y);
        if(cnt1<=cnt2)
        {
            return false;
        }
        return true;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr,arr+n,cmpBit);
    }
};