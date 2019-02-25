#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[110][510], s[110][510], dp[105][510], ant[110][510], c[10000000];
vector<int> v;
vector<int>::reverse_iterator t;
int main()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            cin >> a[i][j];
            int x = a[i][j];
            s[i][j] = s[i][j - 1] + x;
        }

    for ( int i = 1; i <= m; i++ )
        dp[1][i] = a[1][i];

    for ( int i = 2; i <= n - 1; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            dp[i][j] = dp[i - 1][1] + s[i][j];
            ant[i][j] = j;

            for ( int k = 2; k <= j; k++ )
                if ( dp[i][j] > dp[i - 1][k] +  s[i][j] - s[i][k - 1] )
                {
                    dp[i][j] = dp[i - 1][k] +  s[i][j] - s[i][k - 1];
                    ant[i][j] = k;
                }

            for ( int k = j + 1; k <= m; k++ )
                if ( dp[i][j] > dp[i - 1][k] +  s[i][k] - s[i][j - 1] )
                {
                    dp[i][j] = dp[i - 1][k] +  s[i][k] - s[i][j - 1];
                    ant[i][j] = k;
                }
        }

    int rez = INT_MAX, k = 0;

    for ( int i = 1; i <= m; i++ )
        if ( rez > dp[n - 1][i] + a[n][i] )
        {
            rez = dp[n - 1][i] + a[n][i];
            k = i;
            // cout << dp[n][i] << ' '<<i<<endl;
        }

    /*
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= m; j++ )
                cout << ant[i][j] << ' ';

            cout << endl;
        }
    */
    long long i = n - 1;
    long long j = k;
    long long v = 0;
    c[++v] = k;
    //cout << v << ' ' << c[v] << endl;

    while ( i >= 2 )
    {
        if ( j <= ant[i][j] )
            for ( long long t = j; t <= ant[i][j]; t++ )
                c[++v] = t;
        else
            for ( long long t = j; t >= ant[i][j]; t-- )
                c[++v] = t;

        j = ant[i][j];
        i--;
    }

    // cout << v << ' ' << c[v] << endl;

    if ( n != 1 )
        cout << c[v] << ' ';

    for ( long long i = v; i >= 1 ; i-- )
        cout << c[i] << ' ';

    return 0;
}
