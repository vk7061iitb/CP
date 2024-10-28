#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (true)
    {
        int H, U, D, F;
        cin >> H >> U >> D >> F;

        if (H == 0)
        {
            break;
        }

        int day = 1;    // Day
        double h_i = 0; // Initial Height
        double d_c = U; // Distance Climbed

        while (true)
        {
            if (d_c > 0)
            {
                h_i += d_c;
            }

            if (h_i > H)
            {
                cout << "success on day " << day << endl;
                break;
            }

            h_i -= D;

            if (h_i < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }

            d_c -= 0.01 * F * U;

            day++;
        }
    }
    return 0;
}