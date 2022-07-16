class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        int i=0,j=n-1;
        long long sum1=0,sum2=0;
        sum1+=a[0];
        sum2+=a[n-1];
        while(i<=j)
        {
            if(sum1==sum2 and (i-j)==0)
            {
                return i+1;
            }
            else if(sum2>sum1)
            {
                i++;
                sum1+=a[i];
            }
            else if(sum1>sum2)
            {
                j--;
                sum2+=a[j];
            }
            else
            {
                i++;
                j--;
                sum1+=a[i];
                sum2+=a[j];
            }
        }
        return -1;
    }

};
