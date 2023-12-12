
- [基础算法](#基础算法)
  - [快速排序](#快速排序)
  - [归并排序](#归并排序)
  - [整数⼆分算法](#整数分算法)
  - [浮点数⼆分算法](#浮点数分算法)
  - [⾼精度加法](#精度加法)
  - [⾼精度减法](#精度减法)
  - [⾼精度乘低精度](#精度乘低精度)
  - [⾼精度除以低精度](#精度除以低精度)
  - [一维前缀和](#一维前缀和)
  - [二维前缀和](#二维前缀和)
  - [一维差分](#一维差分)
  - [二维差分](#二维差分)
  - [位运算](#位运算)
  - [双指针](#双指针)
  - [离散化](#离散化)
  - [区间合并](#区间合并)

# 基础算法
## 快速排序
```cpp
void quick_sort(int q[], int l, int r) {
	if (l >= r)return;
	int i = l - 1, j = r + 1, x = q[l + r >> 1];
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j)swap(q[i], q[j]);
	}
	quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```
## 归并排序
```cpp
void merge_sort(int q[], int l, int r) {
	if (l >= r)return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j])tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid)tmp[k++] = q[i++];
	while (j <= r)tmp[k++] = q[j++];
	for (i = l, j = 0; i <= r; i++, j++)q[i] = tmp[j];
}
```
## 整数⼆分算法
```cpp

```
## 浮点数⼆分算法
```cpp

```
## ⾼精度加法
C = A + B, A >= 0, B >= 0
```cpp
vector<int>add(vector<int>& A, vector<int>& B) {
	if (A.size() < B.size())return add(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++) {
		t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(t);
	return C;
}
```
```cpp
string a, b; vector<int> A, B; cin >> a >> b;
for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
auto c = add(A, B); //vector<int> c = add(A, B);
for (int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
	
```
## ⾼精度减法
C = A - B, A >= B, A >= 0, B >= 0
```cpp
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
```
```cpp
bool cmp(vector<int>& A, vector<int>& B) {
	if (A.size() != B.size())return A.size() > B.size();
	for (int i = A.size() - 1; i >= 0; i--) {
		return A[i] > B[i];
	}
	return true;
}
string a, b; vector<int> A, B; cin >> a >> b;
for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
vector<int> c;
if (cmp(A, B))c = sub(A, B); else auto c = sub(B, A);
for (int i = c.size() - 1; i >= 0; i--)printf("%d", c[i]);
```
## ⾼精度乘低精度
C = A * b, A >= 0, b >= 0
```cpp
vector<int> mul(vector<int>& A, int b) {
	vector<int>C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++) {
		if (i < A.size())t += A[i] + b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
```
## ⾼精度除以低精度
```cpp
A / b = C ... r, A >= 0, b > 0
vector<int> div(vector<int>& A, int b, int& r) {
	vector<int>C;
	r = 0;
	for (int i = A.size()-1; i >= 0; i--){
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
```
## 一维前缀和
```cpp
s[i] = s[i - 1] + a[i];
//S[i] = a[1] + a[2] + ... a[i];
//a[l] + ... + a[r] = S[r] - S[l - 1];
```
## 二维前缀和
```cpp
s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//S[i, j] = 第i⾏j列格⼦左上部分所有元素的和;
//以(x1, y1)为左上⾓，(x2, y2)为右下⾓的⼦矩阵的和为：;
//S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1];
```
## 一维差分
## 二维差分
## 位运算
## 双指针
## 离散化
## 区间合并