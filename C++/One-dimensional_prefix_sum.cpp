#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 100010;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
int n, m;
int a[N], s[N];
int main()
{
	sync_with_stdio();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}