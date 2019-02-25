#include <iostream>
using namespace std;
int n, d;
int fr[1010];
int a[30][30];
void board ( int i, int n )
{
    int ok = 0;

    if ( n == 0 )
        return;

    if ( n == 1 )
    {
        for ( int j = 1; j <= 1000; j++ )
            if ( fr[j] >= 1 )
            {
                fr[j]--;
                a[i][i] = j;
                ok = 1;
                break;
            }

        if ( ok == 0 )
        {
            cout << "NO";
            exit ( 0 );
        }

        return;
    }
    else
    {
        for ( int d = 1; d <= 1000; d++ )
            if ( fr[d] >= 4 )
            {
                fr[d] -= 4;
                a[i][i + n - 1] = d;
                a[i][i] = d;
                a[i + n - 1][i + n - 1] = d;
                a[i + n - 1][i] = d;
                ok = 1;
                break;
            }

        if ( ok == 0 )
        {
            cout << "NO";
            exit ( 0 );
        }

        for ( int d = 1; d <= n / 2 - 1; d++ )
        {
            ok = 0;

            for ( int j = 1; j <= 1000; j++ )
                if ( fr[j] >= 8 )
                {
                    fr[j] -= 8;
                    a[i + d][i] = j;
                    a[i][i + d] = j;
                    a[i][i + n - 1 - d] = j;
                    a[i + d][i + n - 1] = j;
                    a[i + n - 1 - d][i + n - 1] = j;
                    a[i + n - 1][i + n - 1 - d] = j;
                    a[i + n - 1][i + d] = j;
                    a[i + n - 1 - d][i] = j;
                    ok = 1;
                    break;
                }

            if ( ok == 0 )
            {
                cout << "NO";
                exit ( 0 );
            }
        }

        if ( n % 2 == 1 )
        {
            ok = 0;

            for ( int j = 1; j <= 1000; j++ )
                if ( fr[j] >= 4 )
                {
                    int d = n / 2;
                    fr[j] -= 4;
                    a[i + d][i] = j;
                    a[i][i + d] = j;
                    a[i + n - 1][i + n - 1 - d] = j;
                    a[i + n - 1 - d][i + n - 1] = j;
                    ok = 1;
                    break;
                }

            if ( ok == 0 )
            {
                cout << "NO";
                exit ( 0 );
            }
        }

    }

    board ( i + 1, n - 2 );
}
int x;
int main()
{
    cin >> n;

    for ( int i = 1; i <= n * n; i++ )
    {
        cin >> x;
        fr[x]++;
    }

    board ( 1, n );
    cout << "YES" << endl;

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
            cout << a[i][j] << ' ';

        cout << '\n';
    }


    return 0;
}
