class Solution{   
 
public:
    string solve(int arr[], int n) 
    {
        sort(arr,arr+n);
        string f="";
        string s="";
        for (int i = 0; i < n; i += 2)
        {
            f += (arr[i] + '0');
        }
        for (int i = 1; i < n; i += 2)
        {
            s += (arr[i] + '0');
        }
        string sum="";
        int c=0,i=f.size()-1,j=s.size()-1;
        while(i>=0 && j>=0)
        {
            int temp = 0;
            temp += (f[i] - '0') + (s[j] - '0')+c;
            sum += to_string(temp % 10);
            c = temp / 10;
            j--;
            i--;
        }
        while(i>=0)
        {
            int temp = 0;
            temp += (f[i] - '0') + c;
            sum += to_string(temp % 10);
            c = temp / 10;
            i--;
        }
        while(j>=0)
        {
            int temp = 0;
            temp += (s[j] - '0') + c;
            sum += to_string(temp % 10);
            c = temp / 10;
            j--;
        }
        if(c!=0)
        {
            sum+=to_string(c);
        }
        while(!sum.empty() && sum.back()=='0')
        {
            sum.pop_back();
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};