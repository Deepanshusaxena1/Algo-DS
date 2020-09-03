#include <bits/stdc++.h>
using namespace std;
int calculation(int diff, int sum)
{
    //s1 + s2 = s;
    //s2 = s - s1;
    //s1 - s2 = diff;
    //s1 - s + s1 = diff;
    //2*s1 = diff + s;
    //s1 = (diff + s)/2;
    return (diff + sum)/2;
}
int f(int arr[],int n,int difference)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    int cal = calculation(difference,sum);
    int dp[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        dp[0][i] = false;
    for(int i=0;i<=n;i++)
        dp[i][0] = true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][cal];

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    int difference;
    cin >> difference;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << f(arr,n,difference) << '\n';
}
