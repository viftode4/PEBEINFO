#include <bits/stdc++.h>
using namespace std;
int n, a[60100];
int main()
{
    cin >> n;

    for ( int i = 1; i <= n; i++ )
    {
        a[i] = i;

        for ( int j = 1; j * j <= i; j++ )
            a[i] = min ( a[i], 1 + a[i - j * j] );
    }

    cout << a[n];

    return 0;
}
