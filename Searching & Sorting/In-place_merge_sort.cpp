void mergeInPlace(int a[], int l, int m, int r)
{
    int mx = max(a[m], a[r]) + 1;
 
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r && k <= r) {
        int e1 = a[i] % mx;
        int e2 = a[j] % mx;
        if (e1 <= e2) {
            a[k] += (e1 * mx);
            i++;
            k++;
        }
        else {
            a[k] += (e2 * mx);
            j++;
            k++;
        }
    }
    while (i <= m) {
        int el = a[i] % mx;
        a[k] += (el * mx);
        i++;
        k++;
    }
 
    while (j <= r) {
        int el = a[j] % mx;
        a[k] += (el * mx);
        j++;
        k++;
    }
    for (int i = l; i <= r; i++)
        a[i] /= mx;
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeInPlace(arr, l, m, r);
    }
}