#include<iostream>
using namespace std;
#define N 3
int getMin(int arr[])
{
    int minInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}
int getMax(int arr[])
{
    int maxInd = 0;
    for (int i=1; i<N; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}
int minOf2(int x, int y)
{
    return (x<y)? x: y;
}
void minCashFlowRec(int amount[])
{
    int mxCredit = getMax(amount), mxDebit = getMin(amount);
    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;
    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;
    cout << "Person " << mxDebit << " pays " << min<< " to " << "Person " << mxCredit << endl;
    minCashFlowRec(amount);
}
void minCashFlow(int graph[][N])
{
    int amount[N] = {0};
    for (int p=0; p<N; p++)
       for (int i=0; i<N; i++)
          amount[p] += (graph[i][p] -  graph[p][i]);
 
    minCashFlowRec(amount);
}
int main()
{
    int graph[N][N] = { {0, 1000, 2000},
                        {0, 0, 5000},
                        {0, 0, 0},};
    minCashFlow(graph);
    return 0;
}