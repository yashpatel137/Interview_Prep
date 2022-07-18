class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
	    int k=1;
	    while(k<n)
	    {
	        if(k%2==0 and arr[k]>arr[k-1])
	        {
	            swap(arr[k],arr[k-1]);
	        }
	        else if(k%2==1 and arr[k]<arr[k-1])
	        {
	            swap(arr[k],arr[k-1]);
	        }
	        k++;
	    }
	}
};
