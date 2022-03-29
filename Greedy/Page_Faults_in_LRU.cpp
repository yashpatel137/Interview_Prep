class Solution{
public:
    int pageFaults(int N, int C, int pages[])
    {
        vector<int> ans;
        int faults=0;
        for(int i=0;i<N;i++)
        {
            auto it=find(ans.begin(),ans.end(),pages[i]);
            if(it==ans.end())
            {
                if(ans.size()==C)
                {
                    ans.erase(ans.begin());
                }
                faults++;
            }
            else
            {
                ans.erase(it);
            }
            ans.push_back(pages[i]);
        }
        return faults;
    }
};