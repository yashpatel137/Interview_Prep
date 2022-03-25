#include <bits/stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n)
{
	vector<int> finalSequence;
	sort(a, a + n);
	for (int i = 0; i < n / 2; ++i) 
    {
		finalSequence.push_back(a[i]);
		finalSequence.push_back(a[n - i - 1]);
	}
	if (n % 2 != 0)
		finalSequence.push_back(a[n/2]);
	int MaximumSum = 0;
	for (int i = 0; i < n - 1; ++i) 
    {
		MaximumSum = MaximumSum + abs(finalSequence[i] -finalSequence[i + 1]);
	}
	MaximumSum = MaximumSum + abs(finalSequence[n - 1] -finalSequence[0]);
	return MaximumSum;
}
int main()
{
	int a[] = { 1, 2, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	cout << MaxSumDifference(a, n) << endl;
}
