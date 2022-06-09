#include <iostream>
#include <vector>

using namespace std;

int tri[500][500] = { 0, };

int main(void){
	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];

	for (int i = 1; i < n; i++) {
        tri[i][0] += tri[i - 1][0];
        tri[i][i] += tri[i - 1][i - 1];
		for (int j = 1; j < i; j++) 
			tri[i][j] =	max(tri[i - 1][j],tri[i - 1][j - 1]) + tri[i][j];
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, tri[n - 1][i]);

	cout << ans;
	return 0;

}