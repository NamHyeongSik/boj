//https://j2wooooo.tistory.com/61
#include<iostream>
#include<string>

using namespace std;

int k;
char op[10];
bool use[10];
int ans[10];
long long max_ans;
long long min_ans;

long long makenum()
{
	long long num = 0;
	for (int i = 0; i <= k; i++)
	{
		num = (num * 10) + ans[i];
	}
	return num;
}

void tracking(int num, int idx)
{
	ans[idx] = num;
	use[num] = true;
	if (idx == k)
	{
		// 숫자로 만들기
		long long num_ans = makenum();
		if (min_ans == 0) min_ans = num_ans;
		if (max_ans == 0 || max_ans < num_ans) max_ans = num_ans;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		// 사용하지 않았던 것이고 연산에 올바르면 실행
		if (!use[i])
		{
			if (((op[idx] == '>') && ans[idx] > i) || ((op[idx] == '<') && ans[idx] < i))
			{
				tracking(i, idx + 1);
				ans[idx + 1] = 0;
				use[i] = false;
			}
		}
	}
}

int main(void)
{
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> op[i];
	for (int i = 0; i <= 9; i++) {
		tracking(i, 0);
		use[i] = false;
	}
	string max_val = to_string(max_ans);
	string min_val = to_string(min_ans);
	if (max_val.length() != k + 1)
        cout << "0" + max_val << '\n';
	else
        cout << max_val<<'\n';
	if (min_val.length() != k + 1)
        cout << "0" + min_val << '\n';
	else
        cout << min_val<<'\n';
	return 0;
}
