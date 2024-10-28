// https://onlinejudge.org/external/111/11172.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            cout << ">";
        }
        else if (a < b)
        {
            cout << "<";
        }
        else
        {
            cout << "=";
        }
        cout << endl;
    }
}