#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    double w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;

    int count = 0;
    for (int i = 0; i < p; i++)
    {
        double a, b;
        cin >> a >> b;

        if (a <= x + w && a >= x && b <= y + h && b >= y)
            count++;
        else
        {
            double r = h / 2;
            double dist1 = sqrt(pow((a - x), 2) + pow((b - (y + r)), 2));
            double dist2 = sqrt(pow((a - (x + w)), 2) + pow((b - (y + r)), 2));
            if (dist1 <= r || dist2 <= r)
                count++;
        }
    }
    cout << count;
}