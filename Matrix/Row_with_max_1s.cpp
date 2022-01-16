class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans=-1;
	    for(int c=0;c<m;c++)
	    {
	        for(int r=0;r<n;r++)
	        {
	            if(arr[r][c]==1)
	            {
	                return r;
	            }
	        }
	    }
	    return ans;
	}

};
//Method 2
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int j = m-1;
        while(j>=0 && arr[0][j]==1)
        {
            j--;
        }
        int row = 0;
    
        for(int i=1;i<n;i++)
        {
            while(j>=0 && arr[i][j]==1){
                j--;
                row = i;
            }
        }
        return j==m-1 ? -1 : row;
	}

};