//Method 1
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int i;
        int *ans=new int[2];
        for(i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]>0)
            {
                arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
            }
            else
            {
                ans[0]=abs(arr[i]);
            }
        }
        for(i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
            }
        }
        return ans;
    }
};

//Method 2
vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
    
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
    
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
    
}