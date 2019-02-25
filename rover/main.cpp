#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "rover.in" );
ofstream fout ( "rover.out" );
int cer, p, v;
int n, m, x;
int a[510][510];
int b[510][510];
int nr[510][510];
int viz[510][510];
int maxel;
struct pct
{
    int i, j;
};
deque<pct> q;
int di[] = {0, 0, 1, 0, -1};
int dj[] = {0, 1, 0, -1, 0};
void afisare();
void cer1();
void addvecini ( int i, int j );
void lee ( int m );
void cer2();
int ok ( int i, int j );
int main()
{
    fin >> cer;
    fin >> n;

    if ( cer == 1 )
        cer1();
    else
        cer2();

    return 0;
}
void cer2()
{
    int l = 1;
    int r = maxel;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            fin >> x;
            maxel=max(maxel,x);
            b[i][j] = x;
        }
    r=maxel;
    while ( l < r )
    {
        int mid = ( l + r + 1 ) / 2;
        cout << mid<<' ';

        for ( int i = 1; i <= n; i++ )
            for ( int j = 1; j <= n; j++ )
                a[i][j] = b[i][j] < mid;

        // afisare();

        lee ( mid );
        // fout << nr[n][n] << endl;

        if ( nr[n][n] == 0 )
            l = mid;
        else
            r = mid - 1;
    }

    fout << l;
}
void lee ( int m )
{
    pct x, y;
    x.i = 1;
    x.j = 1;
    q.push_back ( x );
    nr[1][1] = 0;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
            viz[i][j] = 0;

    viz[1][1] = 1;

    while ( !q.empty() )
    {
        x = q.front();

        addvecini ( x.i, x.j );

        y = q.front();

        if ( x.i == y.i && x.j == y. j )
            q.pop_front();
    }
}
void addvecini ( int i, int j )
{
    pct x;

    for ( int d = 1; d <= 4; d++ )
        if ( ok ( i + di[d], j + dj[d] ) && a[i + di[d]][j + dj[d]] == 0 && !viz[i + di[d]][j + dj[d]] )
        {
            x.i = i + di[d];
            x.j = j + dj[d];
            q.push_front ( x );
            nr[x.i][x.j] = nr[i][j];
            viz[x.i][x.j] = 1;
        }
        else if ( ok ( i + di[d], j + dj[d] ) && a[i + di[d]][j + dj[d]] == 1 && !viz[i + di[d]][j + dj[d]] )
        {
            x.i = i + di[d];
            x.j = j + dj[d];
            q.push_back ( x );
            nr[x.i][x.j] = nr[i][j] + 1;
            viz[x.i][x.j] = 1;
        }
}
void cer1()
{
    fin >> m;

    for ( int i = 1; i <= n; i++ )
        for ( int j = 1; j <= n; j++ )
        {
            fin >> x;
            a[i][j] = x < m;
        }

    //afisare();
    lee ( m );
    fout << nr[n][n] << '\n';
}
int ok ( int i, int j )
{
    if ( i < 1 || i > n || j < 1 || j > n )
        return 0;

    return 1;

}
void afisare()
{
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
            fout << a[i][j] << ' ';

        fout << endl;
    }
}
