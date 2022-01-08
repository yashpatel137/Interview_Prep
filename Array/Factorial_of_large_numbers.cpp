#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        for(int i=2;i<=N;i++)
        {
            int c=0;
            for(int j=0;j<ans.size();j++)
            {
                int temp=ans[j]*i+c;
                ans[j]=temp%10;
                c=temp/10;
            }
            while(c!=0)
            {
                ans.push_back(c%10);
                c/=10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}