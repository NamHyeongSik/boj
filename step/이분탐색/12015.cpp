#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://ferrante.tistory.com/54
//가장 긴 수열인 v의 마지막 값보다 들어온 수가 더 크면 push
//그렇지 않다면 들어온 수의 하한을 v에서 찾아, 그 값을 들어온 수로 변환
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (v.empty() || v.back() < a)
            v.push_back(a);
        else
        {
            auto itr = lower_bound(v.begin(), v.end(), a);
            *itr = a;
        }
    }
    cout << v.size();
}