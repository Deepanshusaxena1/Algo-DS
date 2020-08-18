#include "bits/stdc++.h"
using namespace std;
int Binary_Search_Descending(int arr[], int n, int s)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > s)
            l = m + 1;
        else if (arr[m] < s)
            r = m - 1;
        else
            return m;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s;
    cin >> s;
    cout << Binary_Search_Descending(a, n, s) << '\n';
}