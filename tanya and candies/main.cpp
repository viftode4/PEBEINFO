#include <bits/stdc++.h>
using namespace std;
int n;
int nr;
unsigned long long s[2][300010];
unsigned long long sol[2][300010];
int a[300010];
int main()
{
    cin >> n;

    for ( int i = 1; i <= n; i++ )
    {
        cin >> a[i];
        s[i % 2][i] += s[i % 2][i - 2] + a[i];
        s[i % 2][i + 1] = s[i % 2][i];
    }

    for ( int i = 1; i <= n; i++ )
    {
        sol[i % 2][i] = s[i % 2][i] + s[ ( i + 1 ) % 2][n] - s[ ( i + 1 ) % 2][i] - a[i];
        sol[ ( i + 1 ) % 2][i] = s[ ( i + 1 ) % 2][i] + s[i % 2][n] - s[i % 2][i];

        if ( sol[1][i] == sol[0][i] )
            nr++;
    }

    cout << nr;
    return 0;
}
