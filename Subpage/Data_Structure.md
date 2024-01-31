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
  - [字符串哈希](#字符串哈希)

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
## Trie树
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
## 字符串哈希