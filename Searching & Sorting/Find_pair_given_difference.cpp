//Method 1
bool findPair(int arr[], int size, int n){
    set<int> st(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        int sum=n+arr[i];
        if(st.find(sum)!=st.end())
        {
            return true;
        }
    }
    return false;
}

//Method 2
bool findPair(int arr[], int size, int n){
    int i=0,j=1;
    sort(arr,arr+size);
    while(i<size && j<size)
    {
        if(i!=j && (arr[i]-arr[j]==n || arr[j]-arr[i]==n))
        {
            return true;
        }
        else if(arr[j]-arr[i]<n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}