#include <bits/stdc++.h>
using namespace std;
int LCSRecursive(string s, string t, int n, int m)
{
    if(n==0 or m==0)
        return 0;
    if(s[n-1]==t[m-1])
        return 1+LCSRecursive(s,t,n-1,m-1);
    return max(LCSRecursive(s,t,n-1,m),LCSRecursive(s,t,n,m-1));
}
int LCS(string s,string t)
{
    int dp[s.size()+1][t.size()+1];
    for(int i=0;i<=s.size();i++)
        dp[i][0] = 0;
    for(int j=0;j<=t.size();j++)
        dp[0][j] = 0;
    for(int i=1;i<=s.size();i++)
        for(int j=1;j<=t.size();j++)
            if(s[i-1]==t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    return dp[s.size()][t.size()];
}
int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    cout << LCS(s,t) << '\n';
}
