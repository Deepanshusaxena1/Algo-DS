#include <bits/stdc++.h>
const int SIZE = 1005;
using namespace std;
bool SubsetSumRecursive(int arr[], int n, int sum)
{
    if(n == 0)
        return 0;
    if(sum == 0)
        return 1;
    if(arr[n-1]<=sum)
        //  we have option:- include and exclude
        return (SubsetSumRecursive(arr,n-1,sum-arr[n-1]) or SubsetSumRecursive(arr,n-1,sum));
        // we can't include
    return SubsetSumRecursive(arr,n-1,sum);
}
int dp[SIZE][SIZE];
bool SubsetSumTopDown(int arr[], int n, int sum)
{
    // Make sure you have initialized dp with -1 before calling this function.
    if(n==0)
        return 0;
    if(sum==0)
        return 1;
    // Check if we have calculated the value before.
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    if(arr[n-1]<=sum)
        return dp[n][sum] = (SubsetSumTopDown(arr,n-1,sum-arr[n-1]) or SubsetSumTopDown(arr,n-1,sum));
    return dp[n][sum] = SubsetSumTopDown(arr,n-1,sum);
}
int SubsetSumBottomUp(int arr[], int n, int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int j=0;j<=sum;j++)
        dp[0][j]=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    return dp[n][sum];

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int sum = 0;
    cin >> sum;
    memset(dp,-1,sizeof(dp));
    if(SubsetSumBottomUp(arr,n,sum))   
        cout << "YES";
    else 
        cout << "NO";
    cout << '\n';
}

