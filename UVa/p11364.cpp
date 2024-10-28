#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            l = min(l, x);
            r = max(r, x);
        }
        cout << 2 * (r - l) << endl;
    }
    return 0;
}