- [数据结构](#数据结构)
  - [单链表](#单链表)
  - [双链表](#双链表)
  - [栈](#栈)
  - [队列](#队列)
  - [单调栈](#单调栈)
  - [单调队列](#单调队列)
  - [KMP](#kmp)
  - [Trie树](#trie树)
  - [并查集](#并查集)
  - [堆](#堆)
  - [一般哈希](#一般哈希)
  - [BPDS哈希](#BPDS哈希)
  - [字符串哈希](#字符串哈希)
  - [C++STL](#C++STL)

# 数据结构
## 单链表
```
head            存储链表头(表示头节点的下标)
e[i]            存储节点的值(表示节点i的值)
ne[i]           存储节点的next指针(表示节点i的next指针)
idx             表⽰当前⽤到了哪个节点
init()          初始化，head = -1，idx = 0
add_to_head(x)  将x插到头节点
remove_to_head()将头节点删掉
add(k,x)        将x插到下标是k的点后面
remove(k)       将下标是k的点后面的点删掉

for (int i = head; i != -1; i = ne[i]) cout << e[i] << " -> ";

void p() {
    for (int i = head; i != -1; i = ne[i]) {  // 从head向后遍历
        if (ne[i] == -1) cout << e[i];
        else cout << e[i] << " -> ";
    }
    cout << endl;
}

```
```cpp
int head, e[N], ne[N], idx;
void init() {
    head = -1; idx = 0;
}
void add_to_head(int x) {
    e[idx] = x; ne[idx] = head; head = idx++;
}
void remove_to_head() {
    head = ne[head];
}
void add(int k,int x) {
    e[idx] = x; ne[idx] = ne[k]; ne[k] = idx++;
}
void remove(int k) {
    ne[k] = ne[ne[k]];
}
```
## 双链表
```
e[i]            表⽰节点的值
l[i]            表⽰节点的左指针
r[i]            表⽰节点的右指针
idx             表⽰当前⽤到了哪个节点
init()          初始化，0是左端点，1是右端点
insert(k,x)     在节点k的右边插⼊⼀个数x
remove(k)       删除节点k

void p() {
    for (int i = r[0]; i != 1; i = r[i]) {  // 从左向右遍历
        if (r[i] == 1) cout << e[i];
        else cout << e[i] << " -> ";
    }
    cout << endl;
}
```
```cpp
int e[N], l[N], r[N], idx;
void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}
void insert(int k, int x) {
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}
void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}
```
## 栈
```cpp
int stk[N], tt = 0; // tt表⽰栈顶
stk[++tt] = x;      // 向栈顶插⼊⼀个数
tt--;               // 从栈顶弹出⼀个数
stk[tt];            // 栈顶的值
if (tt > 0) {}      // 判断栈是否为空
```
## 队列
普通队列
```cpp
int q[N], hh = 0, tt = -1;  // hh 表⽰队头，tt表⽰队尾
q[++tt] = x;                // 向队尾插⼊⼀个数
hh++;                       // 从队头弹出⼀个数
q[hh];                      // 队头的值
if (hh <= tt) { not empty; }// 判断队列是否为空
else {empty; }
```
循环队列
```cpp
// hh 表⽰队头，tt表⽰队尾的后⼀个位置
int q[N], hh = 0, tt = 0;

// 向队尾插⼊⼀个数
q[tt++] = x;
if (tt == N) tt = 0;

// 从队头弹出⼀个数
hh++;
if (hh == N) hh = 0;

// 队头的值
q[hh];
// 判断队列是否为空
if (hh != tt) {}
```
## 单调栈
常⻅模型：找出每个数左边离它最近的⽐它⼤/⼩的数
```cpp
int tt = 0;
for (int i = 1; i <= n; i++) {
    while (tt && check(stk[tt], i)) tt--;
    stk[++tt] = i;
}
```
## 单调队列
```cpp
//常⻅模型：找出滑动窗⼝中的最⼤值/最⼩值
int hh = 0, tt = -1;
for (int i = 0; i < n; i++) {
    while (hh <= tt && check_out(q[hh])) hh++;  // 判断队头是否滑出窗⼝
    while (hh <= tt && check(q[tt], i)) tt--;
    q[++tt] = i;
}
```
## KMP
```cpp
int n, m;           // n是s的⻓度,m是p的⻓度
int ne[M];
char s[N], p[M];    // s[]是⻓⽂本,p[]是模式串
cin >> m >> p + 1 >> n >> s + 1;
// 求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i++) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j++;
    ne[i] = j;
}
// 匹配
for (int i = 1, j = 0; i <= n; i++) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j++;
    if (j == m) {
        // 匹配成功后的逻辑i和m的关系
        j = ne[j];
    }
}
```
## Trie树
```
// 0号点既是根节点，⼜是空节点
// son[][]存储树中每个节点的⼦节点
// cnt[]存储以每个节点结尾的单词数量
// str[]要插入的单词
```
```cpp
int son[N][26], cnt[N], idx;
char str[N];
void insert(char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}
int query(char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u])return 0;
        p = son[p][u];
    }
    return cnt[p];
}
```
## 并查集
(1)朴素并查集：
```cpp
int p[N];                               //存储每个点的祖宗节点
int find(int x) {                       // 返回x的祖宗节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
for (int i = 1; i <= n; i++) p[i] = i;  // 初始化，假定节点编号是1~n
p[find(a)] = find(b);                   // 合并a和b所在的两个集合：
```
(2)维护size的并查集：
```cpp
int p[N], size[N];                      //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表⽰祖宗节点所在集合中的点的数量
int find(int x) {                       // 返回x的祖宗节点
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
for (int i = 1; i <= n; i++) {          // 初始化，假定节点编号是1~n
    p[i] = i;
    size[i] = 1;
}
size[find(b)] += size[find(a)];         // 合并a和b所在的两个集合：
p[find(a)] = find(b);
```
(3)维护到祖宗节点距离的并查集：
```cpp
int p[N], d[N];                         //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离
int find(int x) {                       // 返回x的祖宗节点
    if (p[x] != x) {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}
for (int i = 1; i <= n; i++) {          // 初始化，假定节点编号是1~n
    p[i] = i;
    d[i] = 0;
}
p[find(a)] = find(b);                   // 合并a和b所在的两个集合：
d[find(a)] = distance;                  // 根据具体问题，初始化find(a)的偏移量
```
## 堆
## 一般哈希
## BPDS哈希

```cpp
// 题目: 给定含有n个整数的序列，要求对这个序列进行去重操作。所谓去重，是指对这个序列中每个重复出现的数，只保留该数第一次出现的位置，删除其余位置。
// 输入: 输入包含两行： 第一行包含一个正整数n（1 ≤ n ≤ 1000000），表示第二行序列中数字的个数； 第二行包含n个整数，整数之间以一个空格分开。每个整数小于等于1000000000。
// 输出: 输出只有一行，按照输入的顺序输出其中不重复的数字，整数之间用一个空格分开。
// 样例
// 	输入:5
// 		10 12 93 12 75
// 	输出:10 12 93 75
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n; cin >> n; //scanf("%d", &n);
    gp_hash_table<int, bool> corder;
    for (int i = 0; i < n; ++i) {
        int now; cin >> now; //scanf("%d", &now);
        if (!corder[now]) {
            cout << now << ' '; //printf("%d ", now);
            corder[now] = true;
        }
    }
}
```
## 字符串哈希
## C++STL
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