/* https://regularmember.tistory.com/90 */
#include <iostream>
#include <string>
using namespace std;
 
int n, m;
int paper[4][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    string s;
 
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            paper[i][j] = s[j] - '0';
        }
    }
 
    int ans = 0;
 
    //모든 경우 구한다.
    //0인 곳은 가로, 1인 곳은 세로
    for (int b = 0; b < (1 << (n*m)); b++) {
        int sum = 0;
 
        //가로모양으로 자른 애들 계산
        for (int i = 0; i < n; i++) {
            int now = 0;
            for (int j = 0; j < m; j++) {
                //정사각형 종이 조각을 한줄로 이어 붙였을 때의 인덱스
                int k = i * m + j;

                //k번째 자리값이 0이다(가로로 자를거다)                
                if ((b & (1 << k)) == 0) {
                    now = now * 10 + paper[i][j];
                }
                else { //1인 경우(세로인 경우) 앞에까지 만들어진 조각을 sum에 더해준다.
                    sum += now;
                    now = 0;
                }
            }
            //한 행이 끝났으면 만들어진 숫자 sum에 더해준다.
            sum += now;
        }

        //세로 모양으로 자른 애들 계산
        for (int j = 0; j < m; j++) {
            int now = 0;
            for (int i = 0; i < n; i++) {
                //정사각형 종이 조각을 한줄로 이어 붙였을 때의 인덱스
                int k = i * m + j;
 
                //세로인 경우에 숫자를 만들어준다.
                if ((b & (1 << k)) != 0) {
                    now = now * 10 + paper[i][j];
                }
                else {
                    sum += now;
                    now = 0;
                }
            }
            sum += now;
        }
        //최댓값과 비교
        if (ans < sum)
            ans = sum;
    }
    cout << ans << '\n';
    return 0;
}
