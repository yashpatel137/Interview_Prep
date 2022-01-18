bool checkValid(string s1, string s2, string res)
{
    int l1=s1.length();
    int l2=s2.length();
    int lr=res.length();
    if((l1+l2)!=lr)
    {
        return false;
    }
    int f=0,i=0,j=0,k=0;
    while(k<lr)
    {
        if(i<l1 && s1[i]==res[k])
        {
            i++;
        }
        else if(j<l2 && s2[j]==res[k])
        {
            j++;
        }
        else
        {
            f=1;
            break;
        }
        k++;
    }
    if(i<l1 || j<l2)
    {
        return false;
    }
    else
    {
        return true;
    }
}