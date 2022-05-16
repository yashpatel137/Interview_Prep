class Solution {
  public:
    int findPosition(int N) 
    {
        int count=0;
        int pos=0;
        while(N>0)
        {
            if(N&1==1)
            {
                count++;
            }
            pos++;
            N=N>>1;
        }
        if(count==1)
        {
            return pos;
        }
        return -1;
    }
};