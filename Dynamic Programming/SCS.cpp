#include <bits/stdc++.h>
using namespace std;
int SCSLength(string s, string t)
{
    int dp[s.size()+1][t.size()+1];
    for(int i=0;i<=s.size();i++)
        dp[i][0] = 0;
    for(int j=0;j<=t.size();j++)
        dp[0][j] = 0;
    for(int i=1;i<=s.size();i++)
        for(int j=1;j<=t.size();j++)
        if(s[i-1] == t[j-1])
            dp[i][j] = dp[i-1][j-1]+1;
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    return s.size() + t.size() - dp[s.size()][t.size()];
}
string SCS(string s, string t) 
{
    int n = s.size();
    int m = t.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=0;j<=m;j++)
        dp[0][j] = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string _scs;
    int i = n;
    int j = m;
    while(i>=1 && j>=1)
    {
        if(s[i-1] == t[j-1])
        {
            _scs += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] == dp[i][j])
        {
            _scs += s[i-1];
            i--;
        }
        else
        {
            _scs += t[j-1];
            j--;
        }
    }
    while(i>=1)
    {
        _scs += s[i-1];
        i--;
    }
    while(j>=1)
    {
        _scs += t[j-1];
        j--;
    }
    reverse(_scs.begin(),_scs.end());
    return _scs;
}
int main()
{
    string s;
    string t;
    cin >> s >> t;
    cout << SCS(s,t) << '\n';
}
