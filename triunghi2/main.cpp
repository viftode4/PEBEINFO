#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "triunghi2.in" );
ofstream fout ( "triunghi2.out" );
long long cer, n, k;
long long v[50];
int main()
{
    fin >> cer >> n >> k;

    for ( int i = 1; i <= n; i++ )
        fin >> v[i];

    sort ( v + 1, v + n + 1 );

    if ( cer == 1 )
    {
        long long a = v[1], b = v[1], c;
        fout << a << ' ' << b << ' ';
        n = 1;

        while ( n <= k )
        {
            c = a + b;
            fout << c << ' ';
            a = b;
            b = c;
            n++;
        }
    }
    else if ( cer == 2 )
    {

        long long a = v[n - 1], b = v[n], c;

        for ( int i = 1; i <= n; i++ )
            fout << v[i] << ' ';

        while ( n <= k )
        {
            c = a + b;
            fout << c << ' ';
            a = b;
            b = c;
            n++;
        }
    }

    return 0;
}
