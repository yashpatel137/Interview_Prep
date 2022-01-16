class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> vec;
        int k=0,j;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                vec.push_back(Mat[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                Mat[i][j]=vec[j+k];
            }
            k=j*(i+1);
        }
        return Mat;
    }
};