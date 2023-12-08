#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
int qmi(int m, int k, int p) {
	int res = 1 % p, t = m;
	while (k) {
		if (k & 1)res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	sync_with_stdio();
	int x, y, p;
	cin >> x >> y >> p;
	cout << qmi(x, y, p);
	return 0;
}
