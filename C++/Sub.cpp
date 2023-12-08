#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void sync_with_stdio() { ios::sync_with_stdio(0); cin.tie(0), cout.tie(0); }
bool cmp(vector<int>& A, vector<int>& B) {
	if (A.size() != B.size())return A.size() > B.size();
	for (int i = A.size()-1; i >=0; i--){
		return A[i] > B[i];
	}
	return true;
}
vector<int>sub(vector<int>& A, vector<int>& B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0)  t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0)C.pop_back();
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
	vector<int> c;
	if (cmp(A, B))c = sub(A, B);
	else auto c = sub(B, A);
	for (int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
	return 0;
}
