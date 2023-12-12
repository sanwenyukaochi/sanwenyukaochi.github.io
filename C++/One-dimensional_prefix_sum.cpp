#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 100010;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
int n, m;
int a[N], s[N];
void printf_f() {
	printf("以下是一维矩阵a[N]\n");
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	printf("以下是一维前缀和矩阵s[N]\n");
	for (int i = 1; i <= n; i++) printf("%d ", s[i]);
	printf("\n");
}
int main()
{
	sync_with_stdio();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
	}
	printf_f();
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}