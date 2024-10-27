#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;

    // Track the double-quote ahs been paired or not
    bool is_paired = false;

    while (true)
    {
        ch = cin.get();
        if (cin.eof())
        {
            break;
        }

        if (ch == '"')
        {
            if (!is_paired)
            {
                cout << "``";
            }
            else
            {
                cout << "''";
            }
            is_paired = !is_paired;
        }
        else
        {
            cout << ch;
        }
    }
    return 0;
}
