 

> #### 文章目录
> 
> *   *   *   [1\. 深度优先搜索（DFS）](#1_DFS_1)
>         *   [例题1 AcWing 842. 排列数字](#1_AcWing_842__14)
>         *   [例题2 AcWing 843. n-皇后问题](#2_AcWing_843_n_82)
>         *   [2\. 宽度/广度优先搜索（BFS）](#2_BFS_226)
>         *   [AcWing 844. 走迷宫](#AcWing_844__239)
>         *   [3\. 树和图的存储](#3__334)
>         *   [4\. 树与图的遍历](#4__355)
>         *   [模板题 AcWing 846. 树的重心](#_AcWing_846__371)
>         *   [模板题 AcWing 847. 图中点的层次](#_AcWing_847__491)
>         *   [5\. 拓扑排序](#5__577)
>         *   [模板题 AcWing 848. 有向图的拓扑序列](#_AcWing_848__611)

#### 1\. 深度优先搜索（[DFS](https://so.csdn.net/so/search?q=DFS&spm=1001.2101.3001.7020)）

**概念**：  
**深度优先搜索**算法（**D**epth **F**irst **S**earch，简称`DFS`）：一种用于遍历或搜索树或图的算法。 沿着树的深度遍历[树的节点](https://so.csdn.net/so/search?q=%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9&spm=1001.2101.3001.7020)，尽可能深的沿着树的分支往下搜索。当节点`v`的所在边都已被搜索过或者在搜索时节点不满足条件，搜索将回溯到发现节点`v`的那条边的上一个节点。整个搜索过程反复进行直到所有节点1都被访问为止。该搜索属于盲目搜索,最糟糕的情况算法时间复杂度为`O(n!)`。

**形象的比喻**：  
如果把深度优先搜索看作一个人的话，那么这个人是一个执着的人，不管往哪条路走，一定会走到头，走不到头不可能往回走的（回溯）。一旦走到尽头，也并不是直接回到起点，而是边往回走边看能不能继续往前走，只有这个人确定当前这个节点所有的路都已走过，没有路再往下走的时候，这时才会往回退一步，重复这个过程，将所有路上的节点都走一遍，这就是深度优先搜索。

**要点**：

*   深度优先搜索采用的存储数据结构为`stack`，空间复杂度为`O(h)`，这里的`h`表示搜索树的高度，同时深搜不具有最短路的性质；
*   在运用`DFS`算法求解题目时，`DFS`搜索的流程是一棵树的形式，可将题目信息转化为一棵与之对应的递归搜索树，可以借助画图来帮我们理清解题思路；
*   `DFS`熟称暴搜，运用`DFS`算法最重要的就是考虑搜索的顺序，同时要注意回溯（回退时恢复到原来的状态，恢复现场）和剪枝。

#### 例题1 AcWing 842. 排列数字

给定一个整数 `n`，将数字 `1∼n` 排成一排，将会有很多种排列方法。  
现在，请你按照字典序将所有的排列方法输出。

**输入格式**  
共一行，包含一个整数 `n`。

**输出格式**  
按字典序输出所有排列方案，每个方案占一行。

**数据范围**  
`1≤n≤7`

**输入样例**：  
`3`

**输出样例**：

    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    

**解题思路**：  
我们先假设有`n`个空位，然后在每个空位上依次填入数字，并且要保证填入当前空位的数还没填过。  
dfs 最重要的是搜索顺序。用什么顺序遍历所有方案。  
对于按字典序输出的全排列问题，以 n = 3 为例，可以这样进行搜索：  
![请添加图片描述](https://img-blog.csdnimg.cn/08575e6944244c3cbceaf740885f7034.png)

**C++代码**：
```cpp
    #include <iostream>
    using namespace std;
    
    const int N = 10;
    
    int n;
    int path[N]; //存放每个位置上具体填入的数字
    bool state[N]; //存放每个数字的使用状态，true表示当前数字被使用，false表示没有被使用过
    
    void dfs(int u) {
        if (u == n) { // 当u = n时，则表明排列中每个位置都已经填入数字，此时输出当前序列
            for (int i = 0; i < n; i++) printf("%d ", path[i]);
            puts("");
            return;
        }
        //当 u != n时，此时就需要在当前位置 u 填入未被使用的数字i
        for (int i = 1; i <= n; i++) { 
            if (!state[i]) {
                path[u] = i; //在当前位置上填入未被使用的数字i
                state[i] = true; // 将i标记为已使用
                dfs(u + 1); //接着递归到下一个位置
                state[i] = false; //回溯恢复现场，回退恢复到原来的状态
            }
        }
    }
    
    int main() {
        cin >> n;
        
        dfs(0); 
        
        return 0;
    }
```

#### 例题2 AcWing 843. n-皇后问题

**n皇后问题**是指将 `n` 个皇后放在 `n×n` 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。  
![请添加图片描述](https://img-blog.csdnimg.cn/fe177752988d4bc686c71e697494ba98.png)  
现在给定整数 `n`，请你输出所有的满足条件的棋子摆法。

**输入格式**  
共一行，包含整数 `n`。

**输出格式**  
每个解决方案占 `n` 行，每行输出一个长度为 `n` 的字符串，用来表示完整的棋盘状态。  
其中`.` 表示某一个位置的方格状态为空，`Q` 表示某一个位置的方格上摆着皇后。  
每个方案输出完成后，输出一个空行。

**注意**：  
行末不能有多余空格。输出方案的顺序任意，只要不重复且没有遗漏即可。

**数据范围**  
`1≤n≤9`

**输入样例**：  
`4`

**输出样例**：

    .Q..
    ...Q
    Q...
    ..Q.
    
    ..Q.
    Q...
    ...Q
    .Q..
    

**解题思路一**：时间复杂度`O(n!)`

由于每一行有且仅有一个皇后，因此可以对行进行深度优先搜索，分别确定每一行的哪一列放皇后。

对于第`r`行的第`i`个位置，判断该位置是否可以放皇后：

*   如果第`r`行的第`i`个位置可以放皇后，则在该位置放皇后，然后处理第`r + 1`行；
*   如果第`r`行的第`i`个位置不能放皇后，则接着判断第`r`行的第`i+1`个位置是否可以放皇后（剪枝：对于不满足要求的位置，不再继续搜索往下的每一行）。

直到`r == n`，说明前`n`行都已经搜索完成，则输出棋盘上每一个位置的值。

**C++代码**：
```cpp
    #include <iostream>
    
    using namespace std;
    
    const int N = 10;
    
    int n;
    char g[N][N]; //存储棋盘中每一个位置上是`.`还是`Q`
    bool col[N], dg[2 * N], udg[2 * N]; //用来标记当前位置[u, i]的列col[i]、对角线dg[u + i]、反对角线udg[n - u + i]上是否存在皇后
    //因为在对角线y = -x + b上的点，截距 b = y + x，因此可以用 y + x 来作为同一条对角线的下标；
    //因为在反对角线y = x + b上的点，截距 b = y - x,由于下标不能为负数，因此可以使用 y - x + n来作为同一条反对角线的下标。	
    void dfs(int u) //深搜第 u 行的哪一列能够放皇后
    {
        if (u == n) // 当u = n时，表明前n行都已放好皇后，将前n行进行输出
        {
            for (int i = 0; i < n; i ++ ) puts(g[i]);
            puts("");
            return;
        }
    
        for (int i = 0; i < n; i ++ ) //遍历第u行的每一个位置
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) //当前位置所在列、对角线、反对角线都没放皇后时
           												  //在该位置放上皇后，然后处理下一行
            {
                g[u][i] = 'Q';
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1);
                col[i] = dg[u + i] = udg[n - u + i] = false; //恢复现场
                g[u][i] = '.';
            }
    }
    
    int main()
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) 
            for (int j = 0; j < n; j ++ )
                g[i][j] = '.'; //将每一个位置初始化为`.`
    
        dfs(0);
    
        return 0;
    }
```

**解题思路二**：

对于棋盘上的每一个点依次进行深度优先搜索，判断当前位置上是否能够放皇后。  
时间复杂度：O(2n2)，每个位置都有两种情况，总共有n2个位置

**C++代码**：
```cpp
    #include <iostream>
    
    using namespace std;
    
    const int N = 10;
    
    int n;
    bool row[N], col[N], dg[N * 2], udg[N * 2];
    char g[N][N];
    
    void dfs(int x, int y, int s) //深搜当前位置[x,y]能不能放皇后，已放的皇后个数为s
    {
        if (y == n) y = 0, x ++ ; //当 y = n 时，表明第x行所有元素搜索完成，接着对下一行的元素进行搜索
    
        if (x == n) //当 x = n 时，表明前n行所有的元素都已搜索完成
        {
            if (s == n) // 如果s = n，表明刚好前 n 行放入了 n 个皇后，将棋盘输出
            {
                for (int i = 0; i < n; i ++ ) puts(g[i]);
                puts("");
            }
            return;
        }
    	// 当前位置不放皇后
        g[x][y] = '.';
        dfs(x, y + 1, s);
    	// 当前位置放皇后
        if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
        {
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
            g[x][y] = 'Q';
            dfs(x, y + 1, s + 1);
            g[x][y] = '.';
            row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        }
    }
    
    int main()
    {
        cin >> n;
    
        dfs(0, 0, 0);
    
        return 0;
    }
```

#### 2\. 宽度/广度优先搜索（BFS）

**概念**：  
**广度优先搜索**（也称**宽度优先搜索**，缩写`BFS`，以下采用广度来描述）是**连通图**的一种遍历策略。因为它的思想是从一个顶点V0开始，辐射状地优先遍历其周围较广的区域，故得名。

**应用场景**：  
一般可以用它做什么呢？一个最直观经典的例子就是走迷宫，我们从起点开始，找出到终点的最短路程，很多**最短路径**算法就是基于广度优先的思想成立的。

**要点**：  
宽度优先搜索采用的存储数据结构为`queue`，空间复杂度为O(2h)，这里的`h`表示搜索树的高度，同时宽搜具有**最短路**的性质；

**例题1**

#### AcWing 844. 走迷宫

给定一个 `n×m` 的二维整数数组，用来表示一个迷宫，数组中只包含 `0` 或 `1`，其中 `0` 表示可以走的路，`1` 表示不可通过的墙壁。  
最初，有一个人位于左上角 `(1,1)` 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。  
请问，该人从左上角移动至右下角 `(n,m)` 处，至少需要移动多少次。  
数据保证 `(1,1)` 处和 `(n,m)` 处的数字为 `0`，且一定至少存在一条通路。

**输入格式**  
第一行包含两个整数 `n` 和 `m`。  
接下来 `n` 行，每行包含 `m` 个整数（`0` 或 `1`），表示完整的二维数组迷宫。

**输出格式**  
输出一个整数，表示从左上角移动至右下角的最少移动次数。

**数据范围**  
`1≤n,m≤100`

**输入样例**：

    5 5
    0 1 0 0 0
    0 1 0 1 0
    0 0 0 0 0
    0 1 1 1 0
    0 0 0 1 0
    

**输出样例**：  
`8`

**解题思路**：  
从起点开始，往前走第一步，记录下所有第一步能走到的点，然后再从第一步能走到的点开始，往前走第二步，记录下所有第二步能走到的点，重复下去，直到走到终点。输出步数即可。

**实现方式：广度优先遍历**

*   用数组 `g` 存储地图，`d` 存储起点到其他各个点的距离。
*   从起点开始广度优先遍历地图。
*   当地图遍历完，就求出了起点到各个点的距离，输出d\[n - 1\]\[m - 1\]即可。
```cpp
    #include <cstring>
    #include <iostream>
    #include <algorithm>
    #include <queue>
    
    using namespace std;
    
    typedef pair<int, int> PII;
    
    const int N = 110;
    
    int n, m;
    int g[N][N], d[N][N]; //用数组g存储地图，d存储起点到其他各个点的距离
    
    int bfs()
    {
        queue<PII> q; //队列q来存储每一步能走到的各个点
    
        memset(d, -1, sizeof d); //初始化每个点到起点的距离为-1
        d[0][0] = 0; // 将起点位置的d初始化为0
        q.push({0, 0}); //首先将起点{0, 0}加入队列
    	//dx和dy分别表示下一步往上、右、下、左四个方向走的偏移量
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
        while (q.size())
        {
            auto t = q.front();
            q.pop();
    
            for (int i = 0; i < 4; i ++ )
            {
                int x = t.first + dx[i], y = t.second + dy[i];
    
                if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
                {
                    d[x][y] = d[t.first][t.second] + 1;
                    q.push({x, y});
                }
            }
        }
    
        return d[n - 1][m - 1];
    }
    
    int main()
    {
        cin >> n >> m;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                cin >> g[i][j];
    
        cout << bfs() << endl;
    
        return 0;
    }
```

#### 3\. 树和图的存储

树是一种特殊的图（无环连通图），与图的存储方式相同。  
无向图（`a->b , b->a`）是一种特殊的有向图，因此，在这里我们只讨论有向图的存储。  
有向图的存储有两种方式：

1.  邻接矩阵`g[a,b]`：时间复杂度为O(n2)，比较浪费空间，常用于存储稠密图。邻接矩阵不能存储重边，一般存储时只保留一条边。
2.  邻接表：每个节点为头结点的单链表存储着从当前节点能走到的那些点。

    // 对于每个点k，开一个单链表，存储k所有可以走到的点。h[k]存储这个单链表的头结点
    int h[N], e[N], ne[N], idx;
    
    // 添加一条边a->b
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
    }
    
    // 初始化
    idx = 0;
    memset(h, -1, sizeof h);
    

#### 4\. 树与图的遍历

时间复杂度为`O(n + m)`，`n`表示点数，`m`表示边数。

**(1) 深度优先遍历**

    int dfs(int u)
    {
        st[u] = true; // st[u] 表示点u已经被遍历过
    
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j]) dfs(j);
        }
    }
    

#### 模板题 AcWing 846. 树的重心

给定一颗树，树中包含 `n` 个结点（编号 `1∼n`）和 `n−1` 条无向边。  
请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。  
**重心定义**：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

**输入格式**  
第一行包含整数 `n`，表示树的结点数。  
接下来 `n−1` 行，每行包含两个整数 `a` 和 `b`，表示点 `a` 和点 `b` 之间存在一条边。

**输出格式**  
输出一个整数 `m`，表示将重心删除后，剩余各个连通块中点数的最大值。

**数据范围**  
1 ≤ n ≤ 105

**输入样例**

    9
    1 2
    1 7
    1 4
    2 8
    2 5
    4 3
    3 9
    4 6
    

**输出样例**

    4
    

![请添加图片描述](https://img-blog.csdnimg.cn/3c580c50e8fb424d9ba9c55394a609ef.png)

**C++代码**

    #include <iostream>
    #include <cstring>
    #include <cstdio>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010, M = N * 2; // 数据范围是10的5次方, 以有向图的格式存储无向图，所以每个节点至多对应2n-2条边
    
    int n;
    int h[N]; // 邻接表存储树，有n个节点，所以需要n个队列头节点
    int e[M], ne[M], idx;
    int ans = N;    // 存储结果
    bool state[N];  // 记录节点是否被访问过，访问过则标记为true
    
    // 插入一条边 a -> b
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    
    // 返回以u为根节点的树中节点的个数
    int dfs(int u) {
        state[u] = true; // 标记当前节点已被遍历
        int size = 0;    // size表示去除当前节点后，连通块中点数的最大值。
        int sum = 0;     // sum表示以当前节点为根节点的子树节点数之和。
        
        // 访问u的每个子节点
        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            //因为每个节点的编号都是不一样的，所以 用编号为下标 来标记是否被访问过
            if (state[j]) continue; 
            
            int s = dfs(j);
            size = max(size, s);
            sum += s;
        }
        size = max(size, n - sum - 1);
        ans = min(ans, size);
        
        return sum + 1;
    }
    
    int main() {
        cin >> n;
        memset(h, -1, sizeof h); //初始化h数组，每个节点都存储着-1，-1表示尾节点
        
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            add(a, b);
            add(b, a);
        }
        
        dfs(1);
        
        cout << ans << endl;
        
        return 0;
    }
    

**(2) 宽度优先遍历**

    queue<int> q;
    st[1] = true; // 表示1号点已经被遍历过
    q.push(1);
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
    
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!st[j])
            {
                st[j] = true; // 表示点j已经被遍历过
                q.push(j);
            }
        }
    }
    

#### 模板题 AcWing 847. 图中点的层次

给定一个 `n` 个点 `m` 条边的有向图，图中可能存在重边和自环。  
所有边的长度都是 `1`，点的编号为 `1∼n`。  
请你求出 `1` 号点到 `n` 号点的最短距离，如果从 `1` 号点无法走到 `n` 号点，输出 `−1`。

**输入格式**

第一行包含两个整数 `n` 和 `m`。  
接下来 `m` 行，每行包含两个整数 `a` 和 `b`，表示存在一条从 `a` 走到 `b` 的长度为 `1` 的边。

**输出格式**  
输出一个整数，表示 `1` 号点到 `n` 号点的最短距离。

**数据范围**  
1≤n,m≤105

**输入样例：**

    4 5
    1 2
    2 3
    3 4
    1 3
    1 4
    

**输出样例**

    1
    

**C++代码**

    #include <iostream>
    #include <cstring>
    #include <cstdio>
    #include <algorithm>
    #include <queue>
    
    using namespace std;
    
    const int N = 100010;
    int n, m;
    int h[N], e[N], ne[N], idx;
    int d[N]; //存储每个节点离起点的距离 
    
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    
    int bfs() {
        memset(d, -1, sizeof d); // 将每个点离起点的距离初始化为-1，后续可通过-1来判断节点是否被遍历过
        
        queue<int> q; //存储层次遍历序列
        d[1] = 0;
        q.push(1);
        
        while (q.size()) {
            int t = q.front();
            q.pop();
            
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                if (d[j] == -1) { // 当d[j] = -1时，表明该节点第一次被遍历到，更新节点到起点的距离，并将其加入队列中
                    d[j] = d[t] + 1;
                    q.push(j);
                }
            }
        }
        return d[n];
    }
    
    int main() {
        cin >> n >> m;
        memset(h, -1, sizeof h);
        
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            add(a, b);
        }
        
        cout << bfs() << endl;
        return 0;
    }
    

#### 5\. 拓扑排序

有向图才可能存在拓扑序列，有向无环图一定存在拓扑序列，有环图一定没有拓扑序列。  
拓扑序列的定义：在拓扑序列中，从前指向后形成的边一定与有向图中对应节点之间的边指向相同。  
有向图中每个节点有两个度：入度（其他节点指向当前节点的边数）、出度（当前节点指向其他节点的边数）  
只要是节点的入度为0，则该节点就可作为拓扑排序的起点，因此拓扑序列不一定唯一。

时间复杂度为`O(n+m)`，`n` 表示点数，`m` 表示边数

    bool topsort()
    {
        int hh = 0, tt = -1;
    
        // d[i] 存储点i的入度
        for (int i = 1; i <= n; i ++ )
            if (!d[i])
                q[ ++ tt] = i;
    
        while (hh <= tt)
        {
            int t = q[hh ++ ];
    
            for (int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                d[j]--;
                if (d[j] == 0)
                    q[ ++ tt] = j;
            }
        }
    
        // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
        return tt == n - 1;
    }
    

#### 模板题 AcWing 848. 有向图的拓扑序列

给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。  
请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

**输入格式**  
第一行包含两个整数 n 和 m。  
接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

**输出格式**  
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。否则输出 −1。

**数据范围**  
1≤n,m≤105

**输入样例**

    3 3
    1 2
    2 3
    1 3
    

**输出样例**

    1 2 3
    

**C++代码**

    #include <iostream>
    #include <algorithm>
    #include <cstring>
    #include <queue>
    
    using namespace std;
    
    const int N = 100010;
    int n, m;
    int h[N], e[N], ne[N], idx;
    int d[N], q[N];
    
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }
    
    bool topsort() {
        int hh = 0, tt = -1;
        
        for (int i = 1; i <= n; i++)
            if (!d[i])
                q[++tt] = i;
        while (hh <= tt) {
            int t = q[hh++];
            for (int i = h[t]; i != -1; i = ne[i]) {
                int j = e[i];
                d[j]--;
                if (d[j] == 0)
                    q[++tt] = j;
            }
        }
        return tt == n - 1;
    }
    
    int main() {
        cin >> n >> m;
        memset(h, -1, sizeof h);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            add(a, b);
            
            d[b]++;
        }
        
        if (!topsort()) puts("-1");
        else {
            for (int i = 0; i < n; i++) cout << q[i] << " ";
            puts("");
        }
        
        return 0;
    }