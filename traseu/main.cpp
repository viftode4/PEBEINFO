#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "traseu.in" );
ofstream fout ( "traseu.out" );
int dx[] = {0, 1, 0, -1, 0, 0, 0};
int dy[] = {0, 0, -1, 0, 1, 0, 0};
int dh[] = {0, 0, 0, 0, 0, -1, 1};
int a[105][105][105];
struct tridi
{
    int x, y, h;
} q[1000010];
vector<tridi> sol;
int n, m;
int x, y, h, v, p;
int ix, iy, ih;
int fx, fy, fh;
int interior ( int h, int x, int y )
{
    if ( h < 1 || h > n || x < 1 || x > n || y < 1 || y > n )
        return 0;

    return 1;
}
int ok ( int h, int x, int y )
{
    if ( !interior ( h, x, y ) )
        return 0;

    if ( a[h][x][y] != 0 )
        return 0;

    return 1;
}
void addvecini ( int x )
{
    for ( int d = 1; d <= 6; d++ )
        if ( ok ( q[x].h + dh[d], q[x].x + dx[d], q[x].y + dy[d] ) )
        {
            v++;
            q[v].h = q[x].h + dh[d];
            q[v].x = q[x].x + dx[d];
            q[v].y = q[x].y + dy[d];
            a[q[v].h][q[v].x][q[v].y] = a[q[x].h][q[x].x][q[x].y] + 1;
        }
}
void lee()
{
    while ( p <= v )
    {
        addvecini ( p );
        p++;
    }
}
int cmp ( int a, int b, int h, int x, int y )
{
    if ( h + dh[a] < h + dh[b] )
        return 0;

    if ( h + dh[a] > h + dh[b] )
        return 1;

    if ( x + dx[a] < x + dx[b] )
        return 0;

    if ( x + dx[a] > x + dx[b] )
        return 1;

    if ( y + dy[a] > y + dy[b] )
        return 1;

    return 0;
}
void dfs ( int h, int x, int y )
{
    int dmin = 0;

    for ( int d = 1; d <= 6; d++ )
        if ( a[h + dh[d]][x + dx[d]][y + dy[d]] - 1 == a[h][x][y] )
        {
            dmin = d;
            break;
        }

    for ( int d = dmin; d <= 6; d++ )
        if ( a[h + dh[d]][x + dx[d]][y + dy[d]] == a[h][x][y] - 1 && cmp ( dmin, d, h, x, y ) )
            dmin = d;


    fout << h + dh[dmin] << ' ' << x + dx[dmin] << ' ' << y + dy[dmin] << '\n';
    dfs ( h + dh[dmin], x + dx[dmin], y + dy[dmin] );
}
int main()
{
    fin >> n >> m;
    fin >> ih >> ix >> iy;
    fin >> fh >> fx >> fy;

    for ( int i = 1; i <= m; i++ )
    {
        fin >> h >> x >> y;
        a[h][x][y] = -1;
    }

    v = p = 1;
    q[1].h = ih;
    q[1].x = ix;
    q[1].y = iy;
    a[ih][ix][iy] = 1;
    lee();
    fout << a[fh][fx][fy] << endl;
    fout << ih << ' ' << ix << ' ' << iy << '\n';
    dfs ( fh, fx, fy );
    return 0;
}
