#include <bits/stdc++.h>
using namespace std;
string s;
char c1, c2;
int main()
{
    int gata = 0;

    while ( !gata )
    {
        cin >> s;
        int rez = 0;

        if ( s == "start" )
        {
            int ant = 1e9;
            int nr = 0;

            while ( !rez )
            {
                nr = ( nr + ant ) / 2;
                cout << "? " << 0 << ' ' << nr << '\n';
                cout << 0 << ' ' << nr % 199997 << endl;
                fflush ( stdout );
                cin >> c1;
                cout << "? " << nr << ' ' << ant << '\n';
                cout << nr % 199997 << ' ' << ant % 199997 << endl;
                fflush ( stdout );
                cin >> c2;

                if ( c1 == 'x' )
                {
                    rez = 0;
                    break;
                }
                else
                {
                    if ( c2 == 'x' )
                        ant = ( nr + ant ) / 2;
                    else
                        nr = ant / 2;
                }
            }

            cout << "! " << nr << '\n';
        }
        else
            return 0;
    }

    return 0;
}
