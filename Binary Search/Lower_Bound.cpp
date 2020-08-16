#include "bits/stdc++.h"
using namespace std;
int Lower_Bound(vector<int> v, int s)
{
    int l = 0;
    int r = v.size() - 1;
    int lowerbound = -1;
    while(l<=r)
    {
        int m = l + (r-l)/2;
        if(v[m]>s)
            r = m - 1;
        else if(v[m]<s)
            l = m + 1;
        else
        {
            lowerbound = m;
            r = m - 1;
        }
    }
    return lowerbound;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i]; 
    int s;
    cin >> s;
    cout << Lower_Bound(v,s) << '\n';
}
