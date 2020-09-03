#include <bits/stdc++.h>
using namespace std;
int total;
int f(int arr[],int n, int currentsum)
{
    if(n==0)
        return abs((total-currentsum)-currentsum);
    // exclude and include
    return min(f(arr,n-1,currentsum),f(arr,n-1,currentsum+arr[n-1]));
}
int MinimumSubsetsum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=sum;i++)
        dp[0][i] = false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    int answer = INT_MAX;
    for(int i=0;i<=sum/2;i++)
        if(dp[n][i])
            answer = min(answer,abs(sum-2*i));
    return answer;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    total = accumulate(arr,arr+n,0);
    cout << MinimumSubsetsum(arr,n,total) << '\n';
}
