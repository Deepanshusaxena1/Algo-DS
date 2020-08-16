#include "bits/stdc++.h"
using namespace std;
int Binary_Search(int arr[],int n,int s)
{
    int l = 0;
    int r = n-1;
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if(arr[m]>s)
            r = m - 1;
        else if(arr[m]<s)
            l = m + 1;
        else
            return m;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int s;
    cin >> s;
    cout << Binary_Search(arr,n,s) << '\n';
}

