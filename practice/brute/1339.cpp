#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int num[26];

//greedy, 모든 단어의 자릿수 합이 제일 큰 알파벳부터 9를 부여.
// ABC, BCA라면 100A + 10B + C + 100B + 10C + A
// -> 101A, 110B, 11C이므로 B에 9, A에 8, C에 7을 주면 됩니다.

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        int count = 1;
        for (int j = tmp.size() - 1; j >= 0; j--) 
        {
            num[tmp[j] - 'A'] += count;
            count *= 10;
        }
    }

    sort(num, num + 26, [](int &a, int &b) {
        return a > b;
    });
    
    int n = 9;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (num[i] == 0)
            break;
        ans += num[i] * n;
        n--;
    }
    cout << ans;
}