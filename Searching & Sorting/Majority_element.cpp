class Solution{
  public:
    int majorityElement(int a[], int size)
    {
        int count=0,temp=0;
        for(int i=0;i<size;i++)
        {
            if(count==0)
            {
                temp=a[i];
            }
            if(a[i]==temp)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int c=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==temp)
            {
                c++;
            }
        }
        if(c>size/2)
        {
            return temp;
        }
        return -1;
    }
};