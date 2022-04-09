#include<bits/stdc++.h>
using namespace std;

void init_code()
{
#ifndef ONLINE_JUDGE
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
#endif
}

int arr[6];
int top[3];
int nex[6];
int fre = 0;

bool isFull()
{
  if (fre == -1)
  {
    return true;
  }
  return false;
}

bool isEmpty(int sn)
{
  if (top[sn] == -1)
  {
    return true;
  }
  return false;
}

void push(int val, int sn)
{
  if (isFull())
  {
    cout << "Stack overflow" << endl;
    return;
  }
  int i = fre;
  fre = nex[i];
  nex[i] = top[sn];
  top[sn] = i;
  arr[i] = val;
}

int pop(int sn)
{
  if (isEmpty(sn))
  {
    cout << "Stack underflow" << endl;
    return INT_MAX;
  }
  int i = top[sn];
  top[sn] = nex[i];
  nex[i] = fre;
  fre = i;
  return arr[i];
}

int main() {
  init_code();
  for (int i = 0; i < 3; i++)
  {
    top[i] = -1;
  }
  for (int i = 0; i < 6; i++)
  {
    nex[i] = i + 1;
  }
  nex[5] = -1;
  push(1, 0);
  push(2, 0);
  push(3, 1);
  push(4, 0);
  push(5, 1);
  cout << "Top of stack 0 is " << pop(0) << endl;
  cout << "Top of stack 1 is " << pop(1) << endl;
  cout << "Top of stack 0 is " << pop(0) << endl;
  cout << "Top of stack 0 is " << pop(0) << endl;
  cout << "Top of stack 1 is " << pop(1) << endl;
  return 0;
}