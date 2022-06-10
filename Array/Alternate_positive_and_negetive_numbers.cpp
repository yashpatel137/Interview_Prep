#include <bits/stdc++.h>
using namespace std;
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> vn,vp;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            vn.push_back(arr[i]);
	        }
	        else
	        {
	            vp.push_back(arr[i]);
	        }
	    }
	    int i=0,j=0,k=0;
	    while(k<n)
	    {
	        if(i!=vp.size())
	        {
	            arr[k++]=vp[i++];
	        }
	        if(j!=vn.size())
	        {
	            arr[k++]=vn[j++];
	        }
	    }
	}
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

//Method 2
void rearrange(int arr[], int n)
{
    int i = 0, j = n-1;
    while (i < j) {
        while (i <= n - 1 and arr[i] > 0)
            i += 1;
        while (j >= 0 and arr[j] < 0)
            j -= 1;
        if (i < j )
            swap(arr[i], arr[j]);
    }
    if (i == 0 || i == n)
        return;
    int k = 0;
    while (k < n && i < n ) 
    { 
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}
