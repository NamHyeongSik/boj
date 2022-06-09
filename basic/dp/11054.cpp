#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int n;
    cin >> n;
    vector<int> arr(n + 1, 0), large(n + 1, 0), small(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
    {
        large[i] = 1;
        for (int j = 1; j <= i; j++)
            if (arr[i] > arr[j] && large[i] < large[j] + 1)
                large[i] = large[j] + 1;
    }

    for (int i = n; i >= 1; i--)
    {
        small[i] = 1;
        for (int j = n; j >= i; j--)
            if (arr[i] > arr[j] && small[i] < small[j] + 1)
                small[i] = small[j] + 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, large[i] + small[i] - 1);
    cout << ans;
	return 0;
}