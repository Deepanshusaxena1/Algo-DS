#include <bits/stdc++.h>
using namespace std;
int UnboundedKnapsackRec(int weight[], int profit[], int n, int W)
{
    if(n==0 or W==0)
        return 0;
    if(weight[n-1]<=W)
        return max(profit[n-1]+UnboundedKnapsackRec(weight,profit,n,W-weight[n-1]),UnboundedKnapsackRec(weight,profit,n-1,W));
    return UnboundedKnapsackRec(weight,profit,n-1,W);
}
int UnboundedKnapsackBottomUp(int weight[], int profit[], int n, int W)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int i=0;i<=W;i++)
        dp[0][i] = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=W;j++)
            if(weight[i-1]<=j)
                dp[i][j] = max(profit[i-1] + dp[i][j-weight[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
    return dp[n][W];
}
int UnboundedKnapsack1(int weight[], int profit[], int n, int W)
{
    int dp[W+1];
    for(int i=0;i<=W;i++)
        dp[i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=W;j++)
            if(weight[i-1]<=j)
                dp[j] = max(dp[j],dp[j-weight[i-1]]+profit[i-1]);
    return dp[W];
}
int main()
{
    int n;
    cin >> n;
    int W;
    cin >> W;
    int weight[n];
    int profit[n];
    for(int i=0;i<n;i++)
        cin >> weight[i];
    for(int i=0;i<n;i++)
        cin >> profit[i];
    cout << UnboundedKnapsack1(weight,profit,n,W) << '\n';
}
