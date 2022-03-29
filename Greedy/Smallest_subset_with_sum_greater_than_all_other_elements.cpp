#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int minElements(int arr[], int n)
{
	int halfSum = 0;
	for (int i = 0; i < n; i++)
		halfSum = halfSum + arr[i];
	halfSum = halfSum / 2;
	sort(arr, arr + n, greater<int>());

	int res = 0, curr_sum = 0;
	for (int i = 0; i < n; i++) 
    {
		curr_sum += arr[i];
		res++;
		if (curr_sum > halfSum)		
			break;
	}
	return res;
}
int main()
{
	int arr[] = {2, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << minElements(arr, n) << endl;
	return 0;
}