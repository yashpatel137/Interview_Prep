#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i) 
    {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void buildHeap(int arr[], int n)
{
	int startIdx = (n / 2) - 1;
	for (int i = startIdx; i >= 0; i--) 
    {
		heapify(arr, n, i);
	}
}
int main()
{
	int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
	int n = sizeof(arr) / sizeof(arr[0]);
	buildHeap(arr, n);
	return 0;
}
