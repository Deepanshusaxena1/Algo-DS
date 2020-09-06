#include <bits/stdc++.h>
using namespace std;
int CoinChangeMinimumCoinsRec(int coins[], int n, int Amount)
{
    if(n==0)
        return INT_MAX-1;
    if(Amount == 0)
        return 0;
    if(coins[n-1]<=Amount)
        return min(1+CoinChangeMinimumCoinsRec(coins,n,Amount-coins[n-1]),CoinChangeMinimumCoinsRec(coins,n-1,Amount));
    return CoinChangeMinimumCoinsRec(coins,n-1,Amount);
}
int CoinChangeMinimumCoinsBottomUp(int coins[], int n, int amount)
{
    int dp[n+1][amount+1];
    for(int i=0;i<=amount;i++)
        dp[0][i] = INT_MAX-1;
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    dp[0][0]=INT_MAX-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=amount;j++)
        {
            if(coins[i-1]<=j)
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][amount]!=INT_MAX-1)
        return dp[n][amount];
    return dp[n][amount];
}
int main()
{
    int n;
    cin >> n;
    int coins[n];
    for(int i=0;i<n;i++)
        cin >> coins[i];
    int Amount;
    cin >> Amount;
    cout << CoinChangeMinimumCoinsBottomUp(coins,n,Amount) << '\n';
}
