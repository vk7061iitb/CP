// https://onlinejudge.org/external/105/10550.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {

        int s, a, b, c;
        cin >> s >> a >> b >> c;

        if (s || a || b || c)
        {
            int rot1 = (s > a) ? (9 * (s - a)) : (360 - 9 * (a - s));
            int rot2 = (b > a) ? (9 * (b - a)) : (360 - 9 * (a - b));
            int rot3 = (b > c) ? (9 * (b - c)) : (360 - 9 * (c - b));

            int total_rot = 720 + rot1 + 360 + rot2 + rot3;

            cout << total_rot << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}
