#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "graf.in" );
ofstream fout ( "graf.out" );
bool viz1[7510];
bool viz2[7510];
int d[7510];
vector <int> a[10005];
queue<int> q;
int n, m, sx, sy, x, y;
void BFS ( bool viz[7510], int x, int y )
{
    q.push ( x );
    d[x] = 1;
    int nr = 0;

    while ( y != nr )
    {
        nr = q.front();
        q.pop();
        for ( auto it : a[nr] )
            if ( !viz[it] )
            {
                d[it] = d[nr] + 1;
                viz[it] = 1;
                q.push ( it );
            }
    }
}
int main()
{
    cin >> n >> m;
    cin >> sx >> sy;

    for ( int i = 1; i <= m; i++ )
    {
        cin >> x >> y;
        a[x].push_back ( y );
        a[y].push_back ( x );
    }

    BFS ( viz1, sx, sy );
    BFS ( viz2, sy, sx );
    cout << endl;

    for ( int i = 1; i <= n; i++ )
        cout << viz1[i] << ' ';

    cout << endl;

    for ( int i = 1; i <= n; i++ )
        cout << viz2[i] << ' ';

    cout << endl;

    return 0;
}
