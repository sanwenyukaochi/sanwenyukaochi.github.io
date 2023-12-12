#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int N = 1010;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
int n, m, q;
int a[N][N], s[N][N];
void printf_f() {
	printf("以下是二维矩阵a[N][N]\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}printf("\n");
	}
	printf("以下是二维前缀和矩阵s[N][N]\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", s[i][j]);
		}printf("\n");
	}
}
int main()
{
	sync_with_stdio();
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}	
	printf_f();
	while (q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	}
	return 0;
}