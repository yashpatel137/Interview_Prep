void copySetBits(unsigned &x, unsigned y, unsigned l, unsigned r)
{
    if(l<1 || r>32)
    {
        return;
    }
    for(int i=l;i<=r;i++)
    {
        int mask=1<<(i-1);
        if(y & mask)
        {
            x=x|mask;
        }
    }
}