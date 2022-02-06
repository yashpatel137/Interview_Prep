class Solution {
  public:
    int countSquares(int N) {
        int cnt=0;
        for(int i=1;i*i<N;i++)
        {
            cnt++;
        }
        return cnt;
    }
};
