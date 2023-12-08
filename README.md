
**目录**
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
- [数据结构](#数据结构)
	- [单链表](#单链表)
	- [双链表](#双链表)
	- [栈](#栈)
	- [队列](#队列)
	- [单调栈](#单调栈)
	- [KMP](#kmp)
	- [Trie树](#trie树)
	- [并查集](#并查集)
	- [堆](#堆)
	- [一般哈希](#一般哈希)
	- [字符串哈希](#字符串哈希)
- [C++STL](#cstl)
- [搜索与图论](#搜索与图论)
	- [树与图的存储](#树与图的存储)
	- [树与图的遍历](#树与图的遍历)
	- [拓扑排序](#拓扑排序)
	- [朴素dijkstra算法](#朴素dijkstra算法)
	- [堆优化版dijkstra](#堆优化版dijkstra)
	- [Bellman-Ford算法](#bellman-ford算法)
	- [spfa 算法](#spfa-算法)
	- [spfa 判断图中是否存在负环](#spfa-判断图中是否存在负环)
	- [floyd 算法](#floyd-算法)
	- [朴素版prime算法](#朴素版prime算法)
	- [kruskal 算法](#kruskal-算法)
	- [染色法判别二分图](#染色法判别二分图)
	- [匈牙利算法](#匈牙利算法)
- [数学知识](#数学知识)
	- [试除法判定质数](#试除法判定质数)
	- [试除法分解质数](#试除法分解质数)
	- [朴素筛法求素数](#朴素筛法求素数)
	- [线性筛法求素数](#线性筛法求素数)
	- [试除法求所有约数](#试除法求所有约数)
	- [约数个数和约数之和](#约数个数和约数之和)
	- [欧几里得算法](#欧几里得算法)
	- [求欧拉函数](#求欧拉函数)
	- [筛法求欧拉函数](#筛法求欧拉函数)
	- [快速幂](#快速幂)
	- [扩展欧几里得算法](#扩展欧几里得算法)
	- [高斯消元](#高斯消元)
	- [递归法求组合数](#递归法求组合数)
	- [通过预处理逆元的方式求组合数](#通过预处理逆元的方式求组合数)
	- [Lucas定理](#lucas定理)
	- [分解质因数求组合数](#分解质因数求组合数)
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
## ⾼精度减法
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
## ⾼精度乘低精度
```cpp

```
## ⾼精度除以低精度
```cpp

```
## 一维前缀和
## 二维前缀和
## 一维差分
## 二维差分
## 位运算
## 双指针
## 离散化
## 区间合并
# 数据结构
## 单链表
## 双链表
## 栈
## 队列
## 单调栈
## KMP
## Trie树
## 并查集
## 堆
## 一般哈希
## 字符串哈希
# C++STL
```cpp
vector 变⻓数组，倍增的思想
	size() 返回元素个数
	empty() 返回是否为空
	clear() 清空
	front()/back()
	push_back()/pop_back()
	begin()/end()
	[]
	⽀持⽐较运算，按字典序

pair<int, int>
	first, 第⼀个元素
	second, 第⼆个元素
	⽀持⽐较运算，以first为第⼀关键字，以second为第⼆关键字（字典序）

string，字符串
	size()/length() 返回字符串⻓度
	empty()
	clear()
	substr(起始下标，(⼦串⻓度)) 返回⼦串
	c_str() 返回字符串所在字符数组的起始地址

queue, 队列
	size()
	empty()
	push() 向队尾插⼊⼀个元素
	front() 返回队头元素
	back() 返回队尾元素
	pop() 弹出队头元素

priority_queue, 优先队列，默认是⼤根堆
	size()
	empty()
	push() 插⼊⼀个元素
	top() 返回堆顶元素
	pop() 弹出堆顶元素
	定义成⼩根堆的⽅式：priority_queue<int, vector<int>, greater<int>> q;

stack, 栈
	size()
	empty()
	push() 向栈顶插⼊⼀个元素
	top() 返回栈顶元素
	pop() 弹出栈顶元素

deque, 双端队列
	size()
	empty()
	clear()
	front()/back()
	push_back()/pop_back()
	push_front()/pop_front()
	begin()/end()
	[]

set, map, multiset, multimap, 基于平衡⼆叉树（红⿊树），动态维护有序序列
	size()
	empty()
	clear()
	begin()/end()
	++, -- 返回前驱和后继，时间复杂度 O(logn)
	
	set/multiset
		insert() 插⼊⼀个数
		find() 查找⼀个数
		count() 返回某⼀个数的个数
		erase()
			(1) 输⼊是⼀个数x，删除所有x O(k + logn)
			(2) 输⼊⼀个迭代器，删除这个迭代器
		lower_bound()/upper_bound()
			lower_bound(x) 返回⼤于等于x的最⼩的数的迭代器
			upper_bound(x) 返回⼤于x的最⼩的数的迭代器
	map/multimap
		insert() 插⼊的数是⼀个pair
		erase() 输⼊的参数是pair或者迭代器
		find()
		[] 注意multimap不⽀持此操作。 时间复杂度是 O(logn)
		lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
	和上⾯类似，增删改查的时间复杂度是 O(1)
	不⽀持 lower_bound()/upper_bound()， 迭代器的++，--

bitset, 圧位
	bitset<10000> s;
	~, &, |, ^
	>>, <<
	==, !=
	[]

	count() 返回有多少个1
	模板 12
	any() 判断是否⾄少有⼀个1
	none() 判断是否全为0
	set() 把所有位置成1
	set(k, v) 将第k位变成v
	reset() 把所有位变成0
	flip() 等价于~
	flip(k) 把第k位取反

```


# 搜索与图论
## 树与图的存储
## 树与图的遍历
## 拓扑排序
## 朴素dijkstra算法
## 堆优化版dijkstra
## Bellman-Ford算法
## spfa 算法
## spfa 判断图中是否存在负环
## floyd 算法
## 朴素版prime算法
## kruskal 算法
## 染色法判别二分图
## 匈牙利算法
# 数学知识
## 试除法判定质数
## 试除法分解质数
## 朴素筛法求素数
## 线性筛法求素数
## 试除法求所有约数
## 约数个数和约数之和
## 欧几里得算法
```cpp
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
```
## 求欧拉函数
## 筛法求欧拉函数
## 快速幂
```cpp
int qmi(int m, int k, int p) {
	int res = 1 % p, t = m;
	while (k) {
		if (k & 1)res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res;
}
```
## 扩展欧几里得算法
## 高斯消元
## 递归法求组合数
## 通过预处理逆元的方式求组合数
## Lucas定理
## 分解质因数求组合数
