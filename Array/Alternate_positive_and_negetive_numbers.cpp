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