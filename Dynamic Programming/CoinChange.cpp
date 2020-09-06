#include <bits/stdc++.h>
using namespace std;
int CoinChangeRec(int coins[], int n,int Amount)
{
    if(n==0)
        return 0;
    if(Amount == 0)
        return 1;
    if(coins[n-1]<=Amount)
        return CoinChangeRec(coins,n-1,Amount)+CoinChangeRec(coins,n,Amount-coins[n-1]);
    return CoinChangeRec(coins,n-1,Amount);
}
int CoinChange(int coins[], int n, int Amount)
{
    int dp[n+1][Amount+1];
    for(int i=0;i<=Amount;i++)
        dp[0][i] = 0;
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=Amount;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][Amount];
}
int main()
{
    int n;
    cin >> n;
    int Amount;
    cin >> Amount;
    int coins[n];
    for(int i=0;i<n;i++)
        cin >> coins[i];
    cout << CoinChange(coins,n,Amount) << '\n';
}

