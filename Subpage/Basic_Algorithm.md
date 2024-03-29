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
bool check(int x) {/* ... */ } // 检查x是否满足某种性质
// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```
## 浮点数⼆分算法
```cpp
bool check(double x) {/* ... */} // 检查x是否满足某种性质
double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
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
A / b = C ... r, A >= 0, b > 0
```cpp
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
//s[x2, y2] - s[x1 - 1, y2] - s[x2, y1 - 1] + s[x1 - 1, y1 - 1];
```
## 一维差分
给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
```cpp
void insert(int l, int r, int c) {
	b[l] += c;
	b[r + 1] -= c;
}
```
```cpp
for (int i = 1; i <= n; i++) {
	insert(i, i, a[i]);//效果类似b[i] = a[i] - a[i - 1];，把A看成是B的前缀和数组，求出原数组B
}
for (int i = 1; i <= 10; i++) {
	b[i] += b[i - 1];
}
```
## 二维差分
给以(x1, y1)为左上⾓，(x2, y2)为右下⾓的⼦矩阵中的所有元素加上c：
S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c
```cpp
void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x2 + 1][y1] -= c;
	b[x1][y2 + 1] -= c;
	b[x2 + 1][y2 + 1] += c;
}
```
## 位运算
求n的第k位数字: n >> k & 1
返回n的最后⼀位1：lowbit(n) = n & -n
```cpp
int lowbit(int x) {
	return x & -x;//return x & ~x +1;
}
/*
求x的二进制有多少个1
int res = 0;
while (x){
	cout << x << '-' << lowbit(x) << "=" << x - lowbit(x) << endl;
	x -= lowbit(x);//x -= x & -x;
	res++;
}
cout << res <<' ';
*/
```
## 双指针
```cpp
for (int i = 0, j = 0; i < n; i++) {
    while (j < i && check(i, j)) {
        j++;
    }
    // 具体问题的逻辑
}
```
## 离散化
```cpp
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) { // 找到第一个大于等于x的位置
	int l = 0, r = alls.size() - 1;
	while (l < r)  {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1; // 映射到1, 2, ...n
}
```
## 区间合并
