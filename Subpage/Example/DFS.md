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