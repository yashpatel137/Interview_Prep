//Using queue
void QueueStack :: push(int x)
{
        q1.push(x);
} 
int QueueStack :: pop()
{
    if(q1.empty())
    {
        return -1;
    }
    while(q1.size()!=1)
    {
        int temp=q1.front();
        q1.pop();
        q2.push(temp);
    }
    int ans = q1.front();
    q1.pop();
    while(!q2.empty())
    {
        int temp=q2.front();
        q2.pop();
        q1.push(temp);
    }
    return ans;
}

//Using array
void MyStack :: push(int x)
{
    top++;
    arr[top]=x;
}
int MyStack :: pop()
{
    if(top==-1)
    {
        return -1;
    }
    return arr[top--];
}