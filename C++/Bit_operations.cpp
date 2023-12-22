#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
void sync_with_stdio() { ios::sync_with_stdio(false); cin.tie(nullptr); }
int lowbit(int x) {
	return x & -x;//return x & ~x +1;
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		int ans = 0;
		while (x){
			cout << x << '-' << lowbit(x) << "=" << x - lowbit(x) << endl;
			x -= lowbit(x);
			ans++;
		}
		cout << ans <<' ';
	}
    return 0;
}
