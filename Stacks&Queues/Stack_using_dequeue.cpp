#include<bits/stdc++.h>
class Stack
{
public:
    stack <int> s;
    Stack()
    {
        
    }
    bool push(int x)
    {
        s.push(x); return true;
    }
    int pop()
    {
         if (s.empty()) return -1;
        int ele= s.top();
         s.pop();
        return ele;
    }
    int top()
    {
        if (s.empty()) return -1;
        return s.top();
    }
    bool isEmpty()
    {
         if (s.empty()) return true;
          return false;
    }
    int size()
    {
        return s.size();
    }
};