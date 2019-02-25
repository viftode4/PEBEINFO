#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int s[110];
int ok ( int nr )
{
    int p = n - nr + 1;
    int sum = 0;
    sum = ( ( p - 1 ) * ( p ) ) / 2;
    sum = s[n] - sum;
    cout << sum << endl;

    if ( sum >= m )
        return 1;

    return 0;
}
int main()
{
    cin >> n >> m;

    for ( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort ( a + 1, a + n + 1 );

    for ( int i = 1; i <= n; i++ )
        s[i] = s[i - 1] + a[i];

    if ( s[n] < m )
    {
        cout << -1;
        return 0;
    }

    int l = 1, r = n;

    while ( l < r )
    {

        cout << l << ' ' << r << endl;
        int mid = ( l + r  ) / 2;

        if ( ok ( mid ) )
            r = mid;
        else
            l = mid + 1;
    }

    cout << l;
}
