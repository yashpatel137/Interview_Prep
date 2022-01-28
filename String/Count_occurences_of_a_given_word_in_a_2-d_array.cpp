class Solution{
    public:
    int find(string target,int i,int j,vector<vector<char>> &mat,int s,int idx)
    {
        int count=0;
        int m=mat.size();
        int n=mat[0].size();
        if(i>=0 && i<m && j>=0 && j<n && target[idx]==mat[i][j])
        {
            char temp=target[idx];
            mat[i][j]=0;
            idx+=1;
            if(idx==s)
            {
                count=1;
            }
            else
            {
                count+=find(target,i+1,j,mat,s,idx);
                count+=find(target,i,j+1,mat,s,idx);
                count+=find(target,i-1,j,mat,s,idx);
                count+=find(target,i,j-1,mat,s,idx);
            }
            mat[i][j]=temp;
        }
        return count;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int ans=0;
        int size=target.length();
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                ans+=find(target,i,j,mat,size,0);
            }
        }
        return ans;
    }
};