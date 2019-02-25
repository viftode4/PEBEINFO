#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "calc.in" );
ofstream fout ( "calc.out" );
int cer, n;
const long long MOD = 1e9 + 7;
void cer1();
void cer2();
int main()
{
    fin >> cer;
    fin >> n;

    if ( cer == 1 )
    {
        cer1();
        return 0;
    }

    cer2();
    return 0;
}
void cer2()
{
    return;
}
void cer1()
{
    long long dp[100001][2];
    dp[1][1] = 1;
    dp[1][0] = 0;
    dp[2][0] = 1;
    dp[2][1] = 1;

    for ( int i = 3; i <= n; i++ )
    {
        dp[i][0] = (  dp[i - 2][0] + dp[i - 2][1] ) % MOD;
        dp[i][1] = ( dp[i - 1][1] + dp[i - 1][0] ) % MOD;
    }
    fout << ( dp[n][1] + dp[n][0] ) % MOD;
}
