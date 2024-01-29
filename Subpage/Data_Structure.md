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

# 数据结构
## 单链表
head    存储链表头
e[]     存储节点的值
ne[]    存储节点的next指针
idx     表⽰当前⽤到了哪个节点
```cpp
int head, e[N], ne[N], idx;
void init() {
    head = -1;
    idx = 0;
}
void add_to_head(int x) {   //将x插到头节点
    e[idx] = x; ne[idx] = head; head = idx++;
}
void remove_to_head() {     //将头节点删掉
    head = ne[head];
}
void add(int k,int x) {     //将x插到下标是k的点后面
    e[idx] = x; ne[idx] = ne[k]; ne[k] = idx++;
}
void remove(int k) {        //将下标是k的点后面的点删掉
    ne[k] = ne[ne[k]];
}
```
## 双链表
## 栈
## 队列
## 单调栈
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