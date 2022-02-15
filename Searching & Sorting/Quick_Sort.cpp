class Solution
{
    public:
    void quickSort(int arr[], int low, int high)
    {
        if(low>=high)
        {
            return;
        }
        int temp=partition(arr,low,high);
        quickSort(arr,low,temp-1);
        quickSort(arr,temp+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot=arr[high];
        int l=low;
        for(int i=low;i<=high-1;i++)
        {
            if(arr[i]<=pivot)
            {
                swap(arr[i],arr[l]);
                l++;
            }
        }
        swap(arr[high],arr[l]);
        return l;
    }
};