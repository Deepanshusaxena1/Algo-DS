#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int RodCutting(int prices[], int n)
{
    int dp[n+1][n+1];
    memset(dp,0,sizeof dp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                dp[i][j] = max(prices[i-1]+dp[i][j-i],dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    return dp[n][n];
}

int main()
 {
	int n;
    cin >> n;
	int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << RodCutting(arr,n) << '\n';
	return 0;
}
