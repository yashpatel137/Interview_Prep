class Solution
{
    public:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    void insertHeap(int &x)
    {
        if(mx.size()==0 || mx.top()>x)
        {
            mx.push(x);
        }
        else
        {
            mn.push(x);
        }
        balanceHeaps();
    }
    
    void balanceHeaps()
    {
        if(mx.size()>mn.size()+1)
        {
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size()>mx.size())
        {
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double getMedian()
    {
        if(mx.size()==mn.size())
        {
            return (mx.top()+mn.top())/2.0;
        }
        return mx.top();
    }
};