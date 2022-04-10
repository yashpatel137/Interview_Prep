void push(stack<int>& s, int a)
{
    s.push(a);
}

bool isFull(stack<int>& s,int n)
{
    if(s.size()==n)
    {
        return true;
    }
    return false;
}

bool isEmpty(stack<int>& s)
{
    if(s.empty())
    {
        return true;
    }
    return false;
}

int pop(stack<int>& s)
{
    s.pop();
}

int getMin(stack<int>& s)
{
    int min=10000;
    while(!s.empty())
    {
        if(s.top()<min)
        {
            min=s.top();
        }
        s.pop();
    }
    return min;
}