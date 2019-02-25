#include <bits/stdc++.h>
using namespace std;
int n;
long long a, b, q;
int main()
{
    cin >> n;

    for ( int i = 1; i <= n; i++ )
    {
        unsigned long long sum = 0;
        cin >> q >> a >> b;

        if ( 2 * a <= b )
            sum = q * a;
        else
            sum = ( b * ( q / 2 ) ) + ( q % 2 ) * a;

        cout << sum << '\n';
    }

    return 0;
}
