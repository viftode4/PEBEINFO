#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "nmult.in" );
ofstream fout ( "nmult.out" );
const int MOD = 666013;
int n, k, w;
int fact[1000001];
int dp[20489][20489];
void f ( const int n )
{
    fact[0] = 1;

    for ( int i = 1; i <= n; i++ )
        fact[i] = ( fact[i - 1] * i  ) % MOD;
}
unsigned int fp ( long long b, long long e )
{
    unsigned long long r = 1;

    while ( e > 0 )
    {
        if ( e % 2 == 1 )
            r = ( r * b ) % MOD;

        b = ( b  * b ) % MOD;
        e /= 2;
    }

    return r ;
}
unsigned long long imod ( const long long x )
{
    return  fp ( x, MOD - 2 );
}
unsigned long long comb (   const long long n, const long long k )
{
    unsigned long long sum = 0;
    sum = ( ( fact[n] * imod ( fact[n - k] ) ) % MOD * imod ( fact[k] ) ) % MOD;
    return sum;
}
unsigned long long calcul ( const long long nrc )
{
    unsigned long long sum = 0;

    for ( int i = k - 1; i <= k + nrc - 2; i++ )
    {
        sum += comb ( i, k - 1 );
        sum = sum % MOD;
    }

    return sum;
}

int main()
{
    fin >> n >> k >> w;
  // f ( n );

    for ( int i = 1; i <= n; i++ )
        dp[1][i] = 1;

    for ( int i = 2; i <= k; i++ )
    {
        for ( int j = 1; j <= n; j++ )
            for ( int t = j - w; t >= 1; t-- )
                dp[i][j] = ( dp[i][j] + dp[i - 1][t] ) % MOD;

    }

    for ( int i = 1; i <= k; i++ )
    {
        for ( int j = 1; j <= n; j++ )
            fout << dp[i][j] << ' ';

        fout << endl;
    }

    long long sum = 0;

    for ( int i = 1; i <= n; i++ )
        sum = ( sum + dp[k][i] ) % MOD;

    //calcul de nrc combinari de k,k+1,k+2,...,k+nrc-1 luate cate k

    long long nrc = n - ( k - 1 ) * w ;
    // fout << calcul ( nrc ) % MOD;
    return 0;
}
