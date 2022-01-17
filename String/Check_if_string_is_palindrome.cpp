class Solution{
public:	
	
	
	int isPalindrome(string s)
	{
	    int low=0,high=s.length()-1;
	    while(low<high)
	    {
	        if(s[low]!=s[high])
	        {
	            return 0;
	        }
	        low++;
	        high--;
	    }
	    return 1;
	}

};