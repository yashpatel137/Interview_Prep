class Solution{
public:
    int inSequence(int A, int B, int C){
        if(A==B)
        {
            return 1;
        }
        else if(A!=B && C==0 || A<B && C<0 || A>B && C>0)
        {
            return 0;
        }
        else if((B-A)%C==0)
        {
            return 1;
        }
        return 0;
    }
};