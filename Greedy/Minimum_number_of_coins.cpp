int findMin(int deno[], int V)
{
    int n=sizeof(deno)/sizeof(deno[0]);
    sort(deno,deno+n);
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        while(V>=deno[i])
        {
            V-=deno[i];
            count++;
        }
    }
    return count;
}