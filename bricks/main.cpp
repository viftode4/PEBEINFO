#include <iostream>
using namespace std;
long long a[510][510];
int main ( void )
{
    int n;
    cin >> n;
    /*
    long long a[501];

    for ( int i = 0; i < 501; i++ )
        a[i] = 0;

    a[0] = 1;

    for ( int i = 1; i <= n; i++ )
    {
        for ( int i = 1; i <= n; i++ )
            cout << a[i] << ' ';

        for ( int j = n; j >= i; j-- )
            a[j] += a[j - i];

        cout << endl;
    }
     cout << a[n] - 1;
    */

    return 0;
}
