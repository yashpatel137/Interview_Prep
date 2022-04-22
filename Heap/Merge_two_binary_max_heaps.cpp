//Method 1
class Solution{
    public:
    void heapify(vector<int> &arr,int i)
    {
        if(i==1)
        {
            return;
        }
        if(arr[i/2-1]<arr[i-1])
        {
            swap(arr[i-1],arr[i/2-1]);
            heapify(arr,i/2);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) 
    {
        while(!b.empty())
        {
            a.push_back(b.back());
            b.pop_back();
            heapify(a,a.size());
        }
        return a;
    }
};

//Method 2
class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i)
    {
       int largest = i;
       int left = 2 * i + 1;
       int right = 2 * i + 2;
    
       if (left < n && arr[left] > arr[largest])
           largest = left;
    
       if (right < n && arr[right] > arr[largest])
           largest = right;
    
       if (largest != i)
       {
           swap(arr[i], arr[largest]);
           heapify(arr, n, largest);
       }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       
       vector<int> ans;
       
       for(auto i: a)
       {
           ans.push_back(i);            
       }
       for(auto i: b)
       {
           ans.push_back(i);
       }
       int size = ans.size();
       for(int i=size/2 - 1; i>=0; i--)
       {
           heapify(ans, size, i);
       }
       return ans;
   }
};