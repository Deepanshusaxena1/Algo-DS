#include "bits/stdc++.h"
using namespace std;
int Number_of_Times_Sorted_Array_is_Rotated(int arr[], int n)
{
    int l = 0;
    int r = n - 1;
    int m = l + (r - l) / 2;
    while (l <= r)
    {
        // cout << m << '\n';
        m = l + (r - l) / 2;
        int current = arr[m];
        int left = arr[(n + m - 1) % n];
        int right = arr[(m + 1) % n];
        if (current < left && current < right)
            return (n - m) % n;
        else if (current <= arr[r])
            r = m - 1;
        else if (current >= arr[l])
            l = m + 1;
        else if (current < arr[r] && current > arr[l])
            r = m - 1;
    }
    return (n - m) % n;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << Number_of_Times_Sorted_Array_is_Rotated(a, n) << '\n';
}