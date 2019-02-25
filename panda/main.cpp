#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "panda.in" );
ofstream fout ( "panda.out" );
int dj[] = {0, 0, 1, 0, -1};
int di[] = {0, 1, 0, -1, 0};
int cer, n, m, t, x, y, mask, nr;
int l, c, k, s, p, v;
int a[510][510];
void afisare();
struct punct
{
    int i, j;
} mancare[250100], q[250100];
void lee();
void addvecini ( int i, int j );
int ok ( int i, int j );
int verificare ( int x, int k );
int main()
{
    fin >> cer;
    fin >> n >> m >> t;
    fin >> l >> c >> k >> s;

    for ( int i = 1; i <= t; i++ )
    {
        fin >> x >> y;
        mancare[i].i = x;
        mancare[i].j = y;
    }

    while ( s > 0 )
    {
        mask = mask << 1;
        mask = mask + 1;
        s--;
    }

    nr = 0;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= m; j++ )
        {
            fin >> x;
            int o = verificare ( x, k );
            nr += o;
            a[i][j] = o;
        }

    if ( cer == 1 )
    {
        fout << nr - 1 << '\n';
        return 0;
    }

    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
            if ( a[i][j] == 1 )
                a[i][j] = 0;
            else
                a[i][j] = -1;
    }

    lee();
    int lmin = INT_MAX, nr = 0;

    for ( int i = 1; i <= t; i++ )
    {
        int o = a[mancare[i].i][mancare[i].j];

        if ( o < lmin && o >= 1 )
        {
            nr = 1;
            lmin = o;
        }
        else if ( o == lmin )
            nr++;
    }

    fout << lmin - 1 << ' ' << nr;
    return 0;
}
void lee()
{
    p = v = 1;
    q[1].i = l;
    q[1].j = c;
    a[l][c] = 1;

    while ( p <= v )
    {
        addvecini ( q[p].i, q[p].j );
        p++;
    }
}
void addvecini ( int i, int j )
{
    for ( int d = 1; d <= 4; d++ )
        if ( ok ( i + di[d], j + dj[d] ) )
        {
            v++;
            q[v].i = i + di[d];
            q[v].j = j + dj[d];
            a[q[v].i][q[v].j] = a[q[p].i][q[p].j] + 1;
        }
}
int ok ( int i, int j )
{
    if ( i < 1 || i > n || j < 1 || j > m )
        return 0;

    if ( a[i][j] == 0 )
        return 1;

    return 0;
}
int verificare ( int x, int k )
{
    int nr = x ^ k;

    if ( ( mask & nr ) == mask )
        return 1;

    return 0;
}
void afisare()
{
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
            fout << a[i][j] << ' ';

        fout << endl;
    }
}
