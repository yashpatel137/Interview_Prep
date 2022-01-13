//Method 1
class Solution{
    public:
    int median(vector<int> &a,vector<int> &b,int n,int m,int ele)
    {
        int k=0,i=0,j=0;
        while(i<n && j<m)
        {
            if(a[i]<b[j])
            {
                k++;
                if(k==ele)
                {
                    return a[i];
                }
                i++;
            }
            else
            {
                k++;
                if(k==ele)
                {
                    return b[j];
                }
                j++;
            }
        }
        while(i<n)
        {
            k++;
            if(k==ele)
            {
                return a[i];
            }
            i++;
        }
        while(j<m)
        {
            k++;
            if(k==ele)
            {
                return b[j];
            }
            j++;
        }
    }
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int n=array1.size();
        int m=array2.size();
        if((n+m)%2!=0)
        {
            return ((double)median(array1,array2,n,m,(n+m)/2+1));
        }
        return ((double)median(array1,array2,n,m,(n+m)/2)+(double)median(array1,array2,n,m,(n+m)/2+1))/2;
    }
};

//Method 2
