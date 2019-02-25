#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "puteri4.in" );
ofstream fout ( "puteri4.out" );
unsigned long long n, e, x, y;
int c[110];
void ciur()
{
    c[1] = c[0] = 1;

    for ( int d = 4; d <= 100; d += 2 )
        c[d] = 1;

    for ( int d = 3; d <= 100; d += 2 )
        if ( ciur[d] == 0 )
        {
            for ( int j = d + d; j <= 100; j += d )
                c[j] = 1;
        }
}
int rad ( unsigned long long ord, unsigned long long nr )
{
    unsigned long long l = 1, r = nr, sol = 1;

    while ( l <= r )
    {
        unsigned long long mid = ( l + r ) / 2, n = 1;
        int ok = 0;

        for ( int i = 1; i <= ord; i++ )
        {
            int ant = n;
            n = n * mid;

            if ( n / mid != ant )
            {
                ok = 1;
                break;
            }
        }

        if ( !ok && n <= nr )
        {
            l = mid + 1;
            sol = mid;
        }
        else
            r = mid - 1;
    }

    return sol;
}
long long ret ( int nr, int p )
{
    long long o = 1;

    if ( nr == 0 )
        return 0;

    for ( int k = 2; k < p; k++ )
    {
        if ( c[k] )
            continue;

        long long r = rad ( k, nr );

        if ( r > 1 )
        {
            o += r;
            o -= ret ( r, k );
        }
        else
            break;

    }

    return o;
}
int main()
{
    fin >> n;
    ciur();

    for ( int i = 1; i <= n; i++ )
    {
        fin >> x >> y;
        fout << ret ( y, 60 ) - ret ( x - 1, 60 ) << endl;
    }

    return 0;
}
