#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x = 0;
    int M;
    cin >> M;
    while (M--)
    {
        string cmd;
        int n;
        cin >> cmd;

        if (cmd == "add")
        {
            cin >> n;
            x |= (1 << n);
        }
        else if (cmd == "remove")
        {
            cin >> n;
            x &= ~(1 << n);
        }
        else if (cmd == "check")
        {
            cin >> n;
            if (x & (1 << n))
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> n;
            x ^= (1 << n);
        }
        else if (cmd == "all")
            x = (1 << 21) - 1;
        else
            x = 0;
    }
}