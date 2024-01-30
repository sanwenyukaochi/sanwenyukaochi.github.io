 

> #### 文章目录
> 
> *   *   *   [1\. Trie树](#1_Trie_2)
>         *   *   [Trie树模版](#Trie_8)
>         *   [模板题 AcWing 835. Trie字符串统计](#_AcWing_835_Trie_43)
>         *   [2\. 并查集](#2__116)
>         *   *   [1）朴素并查集模版](#1_128)
>         *   [模板题 AcWing 836. 合并集合](#_AcWing_836__145)
>         *   *   [2）维护集合中元素数量size的并查集模版](#2size_205)
>         *   [模板题 AcWing 837. 连通块中点的数量](#_AcWing_837__228)
>         *   *   [3）维护到祖宗节点距离的并查集模版](#3_303)
>         *   [模板题 AcWing 240. 食物链](#_AcWing_240__331)
>         *   [3\. 堆](#3__436)
>         *   *   [堆的模版](#_466)
>         *   [模板题1 AcWing 838. 堆排序](#1_AcWing_838__505)
>         *   [模板题2 AcWing 839. 模拟堆](#2_AcWing_839__569)

#### 1\. [Trie树](https://so.csdn.net/so/search?q=Trie%E6%A0%91&spm=1001.2101.3001.7020)

*   高效地存储和查找字符串集合的数据结构

![在这里插入图片描述](https://img-blog.csdnimg.cn/f8ec81d1defc48c4a7c0ff40c8d6a366.png)  
Trie树如上图所示，字符串集合可以通过Trie树进行存储和查找，存储字符串时在字符串的末尾打上标签。

##### Trie树模版

    int son[N][26], cnt[N], idx;
    // 0号点既是根节点，又是空节点
    // son[][]存储树中每个节点的子节点
    // cnt[]存储以每个节点结尾的单词数量
    // idx表示当前使用到了哪个下标
    
    // 插入一个字符串
    void insert(char *str)
    {
        int p = 0; //从根结点开始插入操作
        for (int i = 0; str[i]; i ++ )
        {
            int u = str[i] - 'a'; //将‘a～z’映射到‘0～25’
            if (!son[p][u]) son[p][u] = ++ idx; //当当前子结点不存在时，就创建该子结点
            p = son[p][u]; //将p的子结点作为p，通过for循环，进行下一个字母的插入操作
        }
        cnt[p] ++ ; //在单词结尾处使用一个计数器来统计每个单词的插入次数，插入完成后，就将cnt[p]++
    }
    
    // 查询字符串出现的次数
    int query(char *str)
    {
        int p = 0; //从根结点开始查询操作
        for (int i = 0; str[i]; i ++ )
        {
            int u = str[i] - 'a';
            if (!son[p][u]) return 0; //当该子结点不存在，则表明未查询到这个单词，直接返回0，退出查询
            p = son[p][u];
        }
        return cnt[p];
    }
    

#### 模板题 [AcWing](https://so.csdn.net/so/search?q=AcWing&spm=1001.2101.3001.7020) 835\. Trie字符串统计

维护一个字符串集合，支持两种操作：

1.  `I x` 向集合中插入一个字符串 x；
2.  `Q x` 询问一个字符串在集合中出现了多少次。  
    共有 N 个操作，所有输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

**输入格式**  
第一行包含整数 N，表示操作数。  
接下来 N 行，每行包含一个操作指令，指令为 `I x` 或 `Q x` 中的一种。

**输出格式**  
对于每个询问指令 `Q x`，都要输出一个整数作为结果，表示 x 在集合中出现的次数。  
每个结果占一行。

**数据范围**  
1≤N≤2∗104

**输入样例：**  
5  
I abc  
Q abc  
Q ab  
I ab  
Q ab

**输出样例：**  
1  
0  
1

    #include <iostream>
    using namespace std;
    
    const int N = 1e5 + 10;
    int son[N][26], cnt[N], idx;
    char str[N];
    // 0号点既是根节点，又是空节点
    // son[][]存储树中每个节点的子节点
    // cnt[]存储以每个节点结尾的单词数量
    
    void insert(char *str) {
        int p = 0;
        for (int i = 0; str[i]; i++) {
            int u = str[i] - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    int query(char *str) {
        int p = 0;
        for (int i = 0; str[i]; i++) {
            int u = str[i] - 'a';
            if (!son[p][u]) return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
    
    int main() {
        int n;
        scanf("%d", &n);
        while(n--) {
            char op[2];
            scanf("%s%s", op, str);
            if (*op == 'I') insert(str);
            else printf("%d\n", query(str));
        }
        return 0;
    }
    

#### 2\. 并查集

根据并查集的名称（合并查找集合）便可知并查集的**适用场景**：

1.  将两个集合合并
2.  询问两个元素是否在一个集合当中

**基本原理**：每个集合用一棵树来表示，树根的编号就是整个集合的编号。每个节点存储它的父节点，使用p\[x\]表示x的父节点。

通过解决以下几个问题，来解决并查集的问题：  
问题1：如何判断树根？ 通过判断`p[x] == x`：`if (p[x] == x) 成立`，则表示该节点为根节点；反之，则不是根节点。  
问题2：如何求x的集合编号？`while (p[x] != x) x = p[x];`  
问题3：如何合并两个集合？由于p\[x\]是x的集合编号，p\[y\]是y的集合编号，因此让`p[x] = y;`

##### 1）朴素并查集模版

    	int p[N]; //存储每个点的祖宗节点
    
        // 返回x的祖宗节点（重点）
        int find(int x)
        {
            if (p[x] != x) p[x] = find(p[x]); // 路径压缩包含在这一步
            return p[x];
        }
    
        // 初始化，假定节点编号是1~n
        for (int i = 1; i <= n; i ++ ) p[i] = i;
    
        // 合并a和b所在的两个集合：
        p[find(a)] = find(b);
    

#### 模板题 AcWing 836. 合并集合

一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。  
现在要进行 m 个操作，操作共有两种：

1.  `M a b`，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
2.  `Q a b`，询问编号为 a 和 b 的两个数是否在同一个集合中；

**输入格式**  
第一行输入整数 n 和 m。  
接下来 m 行，每行包含一个操作指令，指令为 `M a b` 或 `Q a b` 中的一种。

**输出格式**  
对于每个询问指令 `Q a b`，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 `Yes`，否则输出 `No`。  
每个结果占一行。

**数据范围**  
1≤n,m≤105

**输入样例：**  
4 5  
M 1 2  
M 3 4  
Q 1 2  
Q 1 3  
Q 3 4

**输出样例：**  
Yes  
No  
Yes

    #include <iostream>
    using namespace std;
    
    const int N = 100010;
    int p[N];
    
    // 返回x的祖宗节点
    int find (int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    int main() {
    	int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) p[i] = i;
        while (m--) {
            char op[2];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            if (*op == 'M') p[find(a)] = find(b);
            else {
                if (find(a) == find(b)) puts("Yes");
                else puts("No");
            }
        }
        return 0;
    }
    

##### 2）维护集合中元素数量size的并查集模版

    	int p[N], size[N];
        //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量
    
        // 返回x的祖宗节点
        int find(int x)
        {
            if (p[x] != x) p[x] = find(p[x]);
            return p[x];
        }
    
        // 初始化，假定节点编号是1~n
        for (int i = 1; i <= n; i ++ )
        {
            p[i] = i;
            size[i] = 1;
        }
    
        // 合并a和b所在的两个集合：
        size[find(b)] += size[find(a)];
        p[find(a)] = find(b);
    

#### 模板题 AcWing 837. 连通块中点的数量

给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。  
现在要进行 m 个操作，操作共有三种：

1.  `C a b`，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
2.  `Q1 a b`，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
3.  `Q2 a`，询问点 a 所在连通块中点的数量；

**输入格式**  
第一行输入整数 n 和 m。  
接下来 m 行，每行包含一个操作指令，指令为 `C a b`，`Q1 a b` 或 `Q2 a` 中的一种。

**输出格式**  
对于每个询问指令 `Q1 a b`，如果 a 和 b 在同一个连通块中，则输出 `Yes`，否则输出 `No`。  
对于每个询问指令 `Q2 a`，输出一个整数表示点 a 所在连通块中点的数量  
每个结果占一行。

**数据范围**  
1 ≤ n,m ≤ 105

**输入样例：**  
5 5  
C 1 2  
Q1 1 2  
Q2 1  
C 2 5  
Q2 5

**输出样例：**  
Yes  
2  
3

    #include <iostream>
    using namespace std;
    
    const int N = 1e5 + 10;
    int p[N], size[N], n, m;
    
    int find (int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    
    int main() {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            size[i] = 1;
        }
        while (m--) {
            string op;
            int a, b;
            cin >> op;
            if (op == "C") {
                cin >> a >> b;
                a = find(a), b = find(b);
                if (a != b) {
                    p[a] = b;
                    size[b] += size[a];
                }
            }
            else if (op == "Q1") {
                cin >> a >> b;
                if (find(a) == find(b)) puts("Yes");
                else puts("No");
            }
            else if (op == "Q2") {
                cin >> a;
                printf("%d\n", size[find(a)]);
            }
        }
        return 0;
    }
    

##### 3）维护到祖宗节点距离的并查集模版

    	int p[N], d[N];
        //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离
    
        // 返回x的祖宗节点
        int find(int x)
        {
            if (p[x] != x)
            {
                int u = find(p[x]);
                d[x] += d[p[x]];
                p[x] = u;
            }
            return p[x];
        }
    
        // 初始化，假定节点编号是1~n
        for (int i = 1; i <= n; i ++ )
        {
            p[i] = i;
            d[i] = 0;
        }
    
        // 合并a和b所在的两个集合：
        p[find(a)] = find(b);
        d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量
    

#### 模板题 AcWing 240. 食物链

动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。  
A 吃 B，B 吃 C，C 吃 A。  
现有 N 个动物，以 1∼N 编号。  
每个动物都是 A,B,C 中的一种，但是我们并不知道它到底是哪一种。  
有人用两种说法对这 N 个动物所构成的食物链关系进行描述：  
第一种说法是 `1 X Y`，表示 X 和 Y 是同类。  
第二种说法是 `2 X Y`，表示 X 吃 Y。  
此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真的，有的是假的。  
当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

1.  当前的话与前面的某些真的话冲突，就是假话；
2.  当前的话中 X 或 Y 比 N 大，就是假话；
3.  当前的话表示 X 吃 X，就是假话。

你的任务是根据给定的 N 和 K 句话，输出假话的总数。

**输入格式**  
第一行是两个整数 N 和 K，以一个空格分隔。  
以下 K 行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中 D 表示说法的种类。  
若 D=1，则表示 X 和 Y 是同类。  
若 D=2，则表示 X 吃 Y。

**输出格式**  
只有一个整数，表示假话的数目。

**数据范围**  
1 ≤ N ≤ 50000,  
0 ≤ K ≤ 100000

**输入样例：**  
100 7  
1 101 1  
2 1 2  
2 2 3  
2 3 3  
1 1 3  
2 3 1  
1 5 5

**输出样例：**  
3

    #include <iostream>
    
    using namespace std;
    
    const int N = 50010;
    
    int n, m;
    int p[N], d[N];
    
    int find(int x)
    {
        if (p[x] != x)
        {
            int t = find(p[x]);
            d[x] += d[p[x]];
            p[x] = t;
        }
        return p[x];
    }
    
    int main()
    {
        scanf("%d%d", &n, &m);
    
        for (int i = 1; i <= n; i ++ ) p[i] = i;
    
        int res = 0;
        while (m -- )
        {
            int t, x, y;
            scanf("%d%d%d", &t, &x, &y);
    
            if (x > n || y > n) res ++ ;
            else
            {
                int px = find(x), py = find(y);
                if (t == 1)
                {
                    if (px == py && (d[x] - d[y]) % 3) res ++ ;
                    else if (px != py)
                    {
                        p[px] = py;
                        d[px] = d[y] - d[x];
                    }
                }
                else
                {
                    if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                    else if (px != py)
                    {
                        p[px] = py;
                        d[px] = d[y] + 1 - d[x];
                    }
                }
            }
        }
    
        printf("%d\n", res);
    
        return 0;
    }
    

#### 3\. 堆

堆（heap）是计算机科学中一类特殊的数据结构的统称。堆通常是一个可以被看做一棵树的数组对象。堆总是满足下列性质：

*   堆中某个结点的值总是不大于或不小于其父结点的值；
*   堆总是一棵**完全二叉树**。
*   将根结点最大的堆叫做最大堆或大根堆，根结点最小的堆叫做最小堆或小根堆。常见的堆有二叉堆、斐波那契堆等。
*   堆是非线性数据结构，相当于一维数组，有两个直接后继。

下图便是一个小根堆的示意图，并将下标从1开始表示，堆的根结点的值为最小值。  
![在这里插入图片描述](https://img-blog.csdnimg.cn/039fd87214d942ff8e4c71b83166742f.png)  
在这里，我们使用数组来存储堆中的元素，如下图：  
![在这里插入图片描述](https://img-blog.csdnimg.cn/e705e976b91245f687371e9cd4d9e3b6.png)  
对于堆中下标为`x`的元素，则`x`的左儿子为`2x`，右儿子为`2x + 1`。

**如何手写一个堆？**

1.  插入一个数x `heap[++size] = x; up[size];`
2.  求集合当中的最小值 `heap[1];`
3.  删除最小值 `heap[1] = heap[size]; size--; down(1);`
4.  删除任意一个元素 `heap[k] = heap[size]; size--; down(k); up(k);`
5.  修改任意一个元素 `heap[k] = x; down(k); up(k);`

**如何建堆可以将时间复杂度降为O(n)？**  
使用`for (int i = n / 2; i; i -- ) down(i);`来建堆，时间复杂度为O(n)。  
解释：例如输入的整数数列为`[5 3 7 11 8 8 7 16 9 6]`，要求将这个数列建堆。  
**输入的数列用完全二叉树表示为：**  
![在这里插入图片描述](https://img-blog.csdnimg.cn/d97d7dc603cc4a7eb235849eb8180287.png)  
接下来进行建堆时，需要将部分节点进行交换，我们可以从节点交换这里入手进行优化，从`n/2`开始循环遍历到根节点，将下标为`1 ~ n/2`节点分别`down`一遍，即使用`for (int i = n / 2; i; i -- ) down(i);`建堆。

为啥要从下标`n/2`开始遍历？ 因为下标大于`n/2`的节点是完全二叉树的叶子节点，不需要进行`down`操作。  
为啥这样遍历的时间复杂度为O(n)? 因为对于完全二叉树，从下往上的第二层最多只有`n/4`个节点，这层的节点最多向下移动一层，即`swap操作最多执行1次`；从下往上的第三层最多只有`n/8`个节点，这层的节点最多向下移动两层，即`swap操作最多执行2次`；依此类推，可得到每一层节点执行`down`操作时，最多交换多少次节点。节点交换的总次数可表示为 n 4 \\frac{n}{4} 4n​ × 1 + n 8 \\frac{n}{8} 8n​ × 2 + n 16 \\frac{n}{16} 16n​ × 3 + …，整理得 n( 1 2 2 \\frac{1}{2^2} 221​ \+ 2 2 3 \\frac{2}{2^3} 232​ \+ 3 2 4 \\frac{3}{2^4} 243​ \+ 4 2 5 \\frac{4}{2^5} 254​ \+ …)，其中 1 2 2 \\frac{1}{2^2} 221​ \+ 2 2 3 \\frac{2}{2^3} 232​ \+ 3 2 4 \\frac{3}{2^4} 243​ \+ 4 2 5 \\frac{4}{2^5} 254​ \+ … < 1，因此节点交换的次数小于n次，时间复杂度为O(n)。

##### 堆的模版

    // h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
    // ph[k]存储第k个插入的点在堆中的下标是几
    // hp[k]存储堆中下标是k的点是第几个插入的点
    int h[N], ph[N], hp[N], size;
    //当用到第k个插入的点时，需要重写swap函数
    // 交换两个点，及其映射关系
    void heap_swap(int a, int b)
    {
        swap(ph[hp[a]],ph[hp[b]]);
        swap(hp[a], hp[b]);
        swap(h[a], h[b]);
    }
    
    void down(int u)
    {
        int t = u;
        if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t)
        {
            heap_swap(u, t);
            down(t);
        }
    }
    
    void up(int u)
    {
        while (u / 2 && h[u] < h[u / 2])
        {
            heap_swap(u, u / 2);
            u >>= 1;
        }
    }
    
    // O(n)建堆
    for (int i = n / 2; i; i -- ) down(i);
    

#### 模板题1 AcWing 838. 堆排序

输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。

**输入格式**  
第一行包含整数 n 和 m。  
第二行包含 n 个整数，表示整数数列。

**输出格式**  
共一行，包含 m 个整数，表示整数数列中前 m 小的数。

**数据范围**  
1 ≤ m ≤ n ≤ 105，  
1 ≤ 数列中元素 ≤ 109

**输入样例：**  
5 3  
4 5 1 3 2

**输出样例：**  
1 2 3

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010;
    
    int n, m;
    int h[N], cnt;
    
    void down(int u)
    {
        int t = u;
        if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t)
        {
            swap(h[u], h[t]);
            down(t);
        }
    }
    
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
        cnt = n;
    
        for (int i = n / 2; i; i -- ) down(i);
    
        while (m -- )
        {
            printf("%d ", h[1]);
            h[1] = h[cnt -- ];
            down(1);
        }
    
        puts("");
    
        return 0;
    }
    

#### 模板题2 AcWing 839. 模拟堆

维护一个集合，初始时集合为空，支持如下几种操作：

1.  `I x`，插入一个数 x；
2.  `PM`，输出当前集合中的最小值；
3.  `DM`，删除当前集合中的最小值（数据保证此时的最小值唯一）；
4.  `D k`，删除第 k 个插入的数；
5.  `C k x`，修改第 k 个插入的数，将其变为 x；

现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

**输入格式**  
第一行包含整数 N。  
接下来 N 行，每行包含一个操作指令，操作指令为 `I x`，`PM`，`DM`，`D k` 或 `C k x` 中的一种。

**输出格式**  
对于每个输出指令 `PM`，输出一个结果，表示当前集合中的最小值。  
每个结果占一行。

**数据范围**  
1 ≤ N ≤ 105  
−109 ≤ x ≤ 109  
数据保证合法。

**输入样例：**  
8  
I -10  
PM  
I -10  
D 1  
C 2 8  
I 6  
PM  
DM

**输出样例：**  
-10  
6

**要点** 题目要求对第`k`个插入的数进行删除和修改操作，因此需要记录第`k`个插入的数和堆中下标的对应关系。使用`ph[k]`存储第`k`个插入的数在堆中的下标，`hp[k]`存储堆中下标为`k`的点是第几个插入的点。在交换两个节点时，需要将第`k`个插入的数和堆中下标的对应关系更新。如下图：  
![请添加图片描述](https://img-blog.csdnimg.cn/8416c79d9a584ce9b3307480f87c551d.png)

    #include <iostream>
    #include <algorithm>
    #include <string.h>
    
    using namespace std;
    
    const int N = 100010;
    
    int h[N], ph[N], hp[N], cnt;
    
    void heap_swap(int a, int b)
    {
        swap(ph[hp[a]],ph[hp[b]]);
        swap(hp[a], hp[b]);
        swap(h[a], h[b]);
    }
    
    void down(int u)
    {
        int t = u;
        if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t)
        {
            heap_swap(u, t);
            down(t);
        }
    }
    
    void up(int u)
    {
        while (u / 2 && h[u] < h[u / 2])
        {
            heap_swap(u, u / 2);
            u >>= 1;
        }
    }
    
    int main()
    {
        int n, m = 0;
        scanf("%d", &n);
        while (n -- )
        {
            char op[5];
            int k, x;
            scanf("%s", op);
            if (!strcmp(op, "I"))
            {
                scanf("%d", &x);
                cnt ++ ;
                m ++ ; //记录第几次插入（设置新的m）
                ph[m] = cnt, hp[cnt] = m;//每次插入都是在堆尾插入（设置ph与hp）
                h[cnt] = x;//记录插入的值 
                up(cnt);
            }
            else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
            else if (!strcmp(op, "DM"))
            {
                heap_swap(1, cnt);
                cnt -- ;
                down(1);
            }
            else if (!strcmp(op, "D"))
            {
                scanf("%d", &k);
                k = ph[k];
                heap_swap(k, cnt);
                cnt -- ;
                up(k);
                down(k);
            }
            else
            {
                scanf("%d%d", &k, &x);
                k = ph[k];
                h[k] = x;
                up(k);
                down(k);
            }
        }
    
        return 0;
    }
    

> 以上模版和笔记均来源：AcWing的算法基础课  
> 链接：https://www.acwing.com/blog/content/277/