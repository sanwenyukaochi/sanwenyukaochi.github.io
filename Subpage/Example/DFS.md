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
```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

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

    .Q..
    ...Q
    Q...
    ..Q.
    
    ..Q.
    Q...
    ...Q
    .Q..
```

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