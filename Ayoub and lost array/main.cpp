#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, l, r;
int nr0, nr1, nr2;
int dp[200010][4];
int main()
{
    cin >> n >> l >> r;
    nr0 = r / 3 - ( l - 1 ) / 3;
    nr1 = ( r + 1 ) / 3 - l / 3;
    nr2 = ( r + 2 ) / 3 - ( l + 1 ) / 3;
    dp[1][0] = nr0;
    dp[1][1] = nr1;
    dp[1][2] = nr2;

    for ( int i = 2; i <= n; i++ )
    {
        dp[i][0] = dp[i - 1][1] * nr2 + dp[i - 1][2] * nr1 + dp[i - 1][0] * nr0;
        dp[i][1] = dp[i - 1][0] * nr1 + dp[i - 1][2] * nr2 + dp[i - 1][1] * nr0;
        dp[i][2] = dp[i - 1][0] * nr2 + dp[i - 1][1] * nr1 + dp[i - 1][2] * nr0;
    }

    cout << dp[n][0];
    return 0;
}
