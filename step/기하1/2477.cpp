#include <iostream>
#include <vector>

using namespace std;

/*
가로/세로가 반복적으로 나오기 때문에, 현재 인덱스(i)에서의 두 변(i, i + 1)을 곱하고,
두 변의 대각에 위치한 변들(i + 3, i + 4)을 곱해주어 둘의 차이중에 제일 큰 값이 면적입니다.
이때 인덱스 값을 그냥 계산하면 배열의 범위를 벗어나므로 mod연산자를 활용했습니다.
*/

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int K;
    cin >> K;
    vector<int> v;
    for (int i = 0; i < 6; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(b);
    }
    int ans = 0;
    int area = -1;
    for (int i = 0; i < 6; i++)
    {
        int tmp = v[i] * v[(i + 1) % 6];
        if (area == -1 || tmp > area)
        {
            area = tmp;
            ans = area - v[(i + 3) % 6] * v[(i + 4) % 6];
        }
    }
    cout << ans * K;
}