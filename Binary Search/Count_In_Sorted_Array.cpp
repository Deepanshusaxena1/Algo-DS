#include "bits/stdc++.h"
using namespace std;
int LowerBound(int arr[], int n, int s)
{
    int l = 0;
    int r = n - 1;
    int lowerbound = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > s)
            r = m - 1;
        else if (arr[m] < s)
            l = m + 1;
        else
        {
            lowerbound = m;
            r = m - 1;
        }
    }
    return lowerbound;
}
int UpperBound(int arr[], int n, int s)
{
    int l = 0;
    int r = n - 1;
    int upperbound = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] > s)
            r = m - 1;
        else if (arr[m] < s)
            l = m + 1;
        else
        {
            upperbound = m;
            l = m + 1;
        }
    }
    return upperbound;
}
int Count(int arr[], int n, int s)
{
    int lower = LowerBound(arr,n,s);
    int upper = UpperBound(arr,n,s);
    if(upper == -1) return 0;
    else    return upper - lower + 1;
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
    cout << Count(a,n,s) << '\n';
    
}