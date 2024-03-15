- [搜索与图论](#搜索与图论)
    - [深度优先搜索DFS](#深度优先搜索DFS)
    - [宽度优先搜索BFS](#宽度优先搜索BFS)
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

# 搜索与图论
## 深度优先搜索
```cpp
int dfs(int u) {
	st[u] = true; // st[u] 表⽰点u已经被遍历过
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (!st[j]) dfs(j);
		}
}
```
## 宽度优先搜索
```cpp
queue<int> q;
st[1] = true;//表示1号点已经被遍历过
q.push(1);
while (q.size()) {
	int t = q.front();
	q.pop();
	for (int i = h[t]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[t]) {
			st[i] = true;
			q.push(j);
		}
	}
}
```
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