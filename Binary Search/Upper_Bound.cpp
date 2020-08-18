#include "bits/stdc++.h"
using namespace std;
int Upper_Bound(vector<int> a, int s)
{
    int l = 0;
    int r = a.size()-1;
    int upperbound = -1;
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if(a[m]<s)
            l = m+1;
        else if(a[m]>s)
            r = m-1;
        else
        {
            upperbound = m;
            l = m + 1;
        }
    }
    return upperbound;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int s;
    cin >> s;
    cout << Upper_Bound(v,s) << '\n';
}