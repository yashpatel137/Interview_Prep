class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++)
    	{
    	    int rev=0,temp,num=a[i];
    	    while(num>0)
    	    {
    	        temp=num%10;
    	        rev=(rev*10)+temp;
    	        num=num/10;
    	    }
    	    if(rev!=a[i])
    	    {
    	        return 0;
    	    }
    	}
    	return 1;
    }
};