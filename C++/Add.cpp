#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
vector<int>add(vector<int>& A, vector<int>& B) {
	if (A.size() < B.size())return add(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t += A[i];
		i < B.size() ? t += B[i] : NULL;
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(t);
	return C;
}
int main()
{
	sync_with_stdio();
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
        for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
        auto c = add(A, B);
	for (int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
	return 0;
}
