class Solution{
  public:
    int middle(int A, int B, int C)
    {
        bool b1=A>B,b2=B>C,b3=C>A;
        if((b1^b3)==0)
        {
            return A;
        }
        if((b1^b2)==0)
        {
            return B;
        }
        if((b2^b3)==0)
        {
            return C;
        }
    }
};