#include <bits/stdc++.h>
using namespace std;
int LCSubstring(string s, string t, int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=0;i<=m;i++)
        dp[0][i] = 0;
    int _count = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                _count = max(_count,dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return _count;
}
int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    cout << LCSubstring(s,t,s.size(),t.size()) << '\n';
}

