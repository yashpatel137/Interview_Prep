class Solution{
    public:
    int countBitsFlip(int a, int b)
    {
        int count=0;
        int Xor=a^b;
        while(Xor>0)
        {
            if(Xor&1)
            {
                count++;
            }
            Xor=Xor>>1;;
        }
        return count;
    }
};