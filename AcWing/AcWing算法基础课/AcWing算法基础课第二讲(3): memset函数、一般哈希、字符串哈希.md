 

> #### 文章目录
> 
> *   *   *   [1\. memset的用法详解](#1_memset_2)
>         *   [2\. 一般哈希](#2__26)
>         *   [模板题 AcWing 840. 模拟散列表](#_AcWing_840__87)
>         *   [3\. 字符串哈希](#3__217)
>         *   [模板题 AcWing 841. 字符串哈希](#_AcWing_841__255)

#### 1\. memset的用法详解

**memset简介**  
`memset`是一个初始化函数，作用是将某一块内存全部设置为指定的值。

    void *memset(void *s, int c, size_t n); 
    

*   s指向要填充的内存块。
*   c是要被设置的值。
*   n是要被设置该值的字符数。
*   返回类型是一个指向存储区s的指针。

[memset函数](https://so.csdn.net/so/search?q=memset%E5%87%BD%E6%95%B0&spm=1001.2101.3001.7020)是按照**字节**对内存块进行初始化，所以一般用它将int[数组初始化为0](https://so.csdn.net/so/search?q=%E6%95%B0%E7%BB%84%E5%88%9D%E5%A7%8B%E5%8C%96%E4%B8%BA0&spm=1001.2101.3001.7020)和-1。一个字节的实际范围应该在0~255，因为memset函数只能取c的后八位给所输入范围的每个字节。也就是说无论c多大只有后八位二进制是有效的。  
初始化为0: `memset(s, 0, sizeof s);`  
初始化为-1: `memset(s, -1, sizeof s);`  
由于一个`int`型的数占`4个字节`，初始化为`0`时，将每个字节都初始化为`0`即可；初始化为`-1`时，用二进制表示中，`-1`的32位的每一位都是`1`，所以可用`-1`将整个内存块初始化为`-1`。

在算法竞赛中，我们常常需要用到设置一个常量用来代表“[无穷大](https://so.csdn.net/so/search?q=%E6%97%A0%E7%A9%B7%E5%A4%A7&spm=1001.2101.3001.7020)”。比如对于int类型的数，有的人会采用`INT_MAX`，即`0x7fffffff`作为无穷大。但是以`INT_MAX`为无穷大常常面临一个问题，即加一个其他的数会溢出。而这种情况在动态规划，或者其他一些递推的算法中常常出现，很有可能导致算法出问题。所以在算法竞赛中，我们常采用`0x3f3f3f3f`来作为**无穷大**。`0x3f3f3f3f`主要有如下好处：

1.  `0x3f3f3f3f`的十进制为`1061109567`，和`INT_MAX`一个数量级，即109数量级，而一般场合下的数据都是小于109的。
2.  `0x3f3f3f3f * 2 = 2122219134`，无穷大相加依然不会溢出。

可以使用`memset(array, 0x3f, sizeof(array))`来为数组设初值为`0x3f3f3f3f`，因为这个数的每个字节都是`0x3f`。

#### 2\. 一般哈希

哈希表的**主要用途**：将一个比较大的值域（10-9~ 109）映射到一个比较小的空间(从0～N，其中N = 105~106）。

哈希表的**存储结构**：**开放寻址法**和**拉链法**。

哈希函数常表示为`h(x)`，则h(x) ∈ \\in ∈ \[0, N)，其中`N`为质数，这里取大于105且最靠近105的质数。要将`x`通过哈希函数映射为`h(x)`，最常使用的哈希函数为 `h(x) = x % N`。  
**为啥要将N取为质数？** 由于通过哈希函数映射后，可能会出现不同的`x`映射到哈希表中同一个`h(x)`，这就造成了冲突，将`N`取为质数，可以最大限度的降低冲突的发生。  
由于可能将不同的`x`映射到同一个`h(x)`，这就造成了冲突，因此在存储哈希表时，需要将这些不同的映射关系都存储下来，可通过**开放寻址法**和**拉链法**实现。

**拉链法**  
当不同的`x`通过哈希函数映射到同一个值`k`造成冲突时，通过一个单链表来存储`x`。  
![在这里插入图片描述](https://img-blog.csdnimg.cn/b3446abbb2934f75a4cff9bc2c693da3.png)  
**拉链法模版**

    	int h[N], e[N], ne[N], idx;
    
         向哈希表中插入一个数
        void insert(int x)
        {
            int k = (x % N + N) % N;
            e[idx] = x;
            ne[idx] = h[k];
            h[k] = idx ++ ;
        }
    
         在哈希表中查询某个数是否存在
        bool find(int x)
        {
            int k = (x % N + N) % N;
            for (int i = h[k]; i != -1; i = ne[i])
                if (e[i] == x)
                    return true;
    
            return false;
        }
    

**开放寻址法**（蹲坑法）  
将`x`映射到哈希表的`h(x)`，开放寻址一般需要将数组`h(x)`的长度扩大到插入的元素个数的两倍。

如`h(x) = k`

1.  添加: 先找到`k`，然后从第`k`个坑位开始，从前往后找，直到找到第一个空的坑位为止，然后把`x`插入进去
2.  查找: 从第`k`个坑位开始，从前往后找，每次看当前坑位有没有人。如果当前坑位有人并且是`x`，则我们就找到了`x`；如果当前坑位有人不是`x`，我们就继续看下一个坑位；如果当前坑位没人，则说明`x`不存在。
3.  删除: 和拉链法的删除类似，从前往后遍历，按照查找的方式来找`x`，如果找到了`x`，一般不会把`x`真正删除，而且把数组中`x`所在的位置打上一个标记，标记`x`是否被删除。

**开放寻址法模版**

    	int h[N];
    
         如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
        int find(int x)
        {
            int t = (x % N + N) % N;
            while (h[t] != null && h[t] != x)
            {
                t ++ ;
                if (t == N) t = 0;
            }
            return t;
        }
    

#### 模板题 AcWing 840. 模拟散列表

维护一个集合，支持如下几种操作：

1.  `I x`，插入一个数 x；
2.  `Q x`，询问数 x 是否在集合中出现过；  
    现在要进行 N 次操作，对于每个询问操作输出对应的结果。

**输入格式**  
第一行包含整数 N，表示操作数量。  
接下来 N 行，每行包含一个操作指令，操作指令为 `I x`，`Q x` 中的一种。

**输出格式**  
对于每个询问指令 `Q x`，输出一个询问结果，如果 x 在集合中出现过，则输出 `Yes`，否则输出 `No`。  
每个结果占一行。

**数据范围**  
1 ≤ N ≤ 105  
−109 ≤ x ≤ 109

**输入样例：**  
5  
I 1  
I 2  
I 3  
Q 2  
Q 5

**输出样例：**  
Yes  
No

**1）开放寻址法**

    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    const int N = 200003, null = 0x3f3f3f3f;
    
    int h[N];
    
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }
    
    int main()
    {
        memset(h, 0x3f, sizeof h);
    
        int n;
        scanf("%d", &n);
    
        while (n -- )
        {
            char op[2];
            int x;
            scanf("%s%d", op, &x);
            if (*op == 'I') h[find(x)] = x;
            else
            {
                if (h[find(x)] == null) puts("No");
                else puts("Yes");
            }
        }
    
        return 0;
    }
    

**2）拉链法**

    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    const int N = 100003;
    
    int h[N], e[N], ne[N], idx;
    
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }
    
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;
    
        return false;
    }
    
    int main()
    {
        int n;
        scanf("%d", &n);
    
        memset(h, -1, sizeof h);
    
        while (n -- )
        {
            char op[2];
            int x;
            scanf("%s%d", op, &x);
    
            if (*op == 'I') insert(x);
            else
            {
                if (find(x)) puts("Yes");
                else puts("No");
            }
        }
    
        return 0;
    }
    

#### 3\. 字符串哈希

**核心思想**：将字符串看成`P`进制数，`P`的经验值是`131`或`13331`，取这两个值的冲突概率低。  
**小技巧**：取模的数用`2^64`，这样直接用`unsigned long long`存储，溢出的结果就是取模的结果。  
**字符串哈希方式**：字符串前缀哈希法

举例说明：  
假如字符串`str = "ABCABDEFG"`，要求计算该字符串的任意子串哈希值，则可使用字符串前缀哈希法

*   h\[0\] = 0; （⚠️注意：不能将子串映射成0）
*   h\[1\] = "A"的hash值
*   h\[2\] = "AB"的hash值
*   h\[3\] = "ABC"的hash值
*   h\[4\] = "ABCA"的hash值
*   …
*   h\[9\] = "ABCABDEFG"的hash值

hash值的计算过程：  
假如`"ABCD"`的`p`进制表示为`1234`，则`"ABCD"`的十进制表示为1×p3 \+ 2×p2 \+ 3×p1+4×p0，所以可以将`"ABCD"`映射为(1×p3 \+ 2×p2 \+ 3×p1+4×p0) % 264

**字符串哈希模版**

    typedef unsigned long long ULL;
    ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64
    
    // 初始化
    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    
    // 计算子串 str[l ~ r] 的哈希值
    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    

#### 模板题 AcWing 841. 字符串哈希

给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 **l1,r1,l2,r2**，请你判断 \[l1,r1\] 和 \[l2,r2\] 这两个区间所包含的字符串子串是否完全相同。  
字符串中只包含大小写英文字母和数字。

**输入格式**  
第一行包含整数 n 和 m，表示字符串长度和询问次数。  
第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。  
接下来 m 行，每行包含四个整数 **l1,r1,l2,r2**，表示一次询问所涉及的两个区间。  
注意，字符串的位置从 1 开始编号。  
**输出格式**  
对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 `Yes`，否则输出 `No`。  
每个结果占一行。

**数据范围**  
1 ≤ n, m ≤ 105

**输入样例：**  
8 3  
aabbaabb  
1 3 5 7  
1 3 6 8  
1 2 1 2

**输出样例：**  
Yes  
No  
Yes

**解题思路：**  
(字符串哈希) O(n)+O(m)  
全称字符串前缀哈希法，每个字符用ascii 码表示，把字符串变成一个`p`进制数字（哈希值），实现不同的字符串映射到不同的数字。  
对形如 X1X2X3⋯Xn−1Xn 的字符串,采用字符的ascii 码乘上 `p` 的次方来计算哈希值。

X1X2X3⋯Xn−1Xn的哈希值为 (X1 × Pn−1 \+ X2 × Pn−2 \+ ⋯ \+ Xn−1 × P1 \+ Xn × P0) mod Q

⚠️注意事项：

1.  任意字符不可以映射成`0`，否则会出现不同的字符串都映射成`0`的情况，比如`A`,`AA`,`AAA`皆为`0`
2.  冲突问题：通过巧妙将`p`和`Q`设置为`p = 131 或 13331`，`Q` = 264，`p`和`Q`取以上经验值时一般不会产生冲突。

问题是比较不同区间的子串是否相同，就转化为不同区间的子串哈希值是否相同。  
求一个字符串的哈希值就相当于求前缀和，求一个字符串的子串哈希值就相当于求部分和。

字符串前缀`str[1~i]`的哈希值 `h[i] = h[i - 1] * p + str[i]`，`i∈[1,n]`，str为字符串数组  
字符串的子串`str[l~r]`的哈希值 `h[l~r] = h[r] - h[l - 1] * p[r - l + 1]`  
子串`str[l~r]`的哈希值理解过程: 比如求 `ABCDE` 的子串 `DE` 的hash值，用 `ABCDE` 的哈希值`h[5]`减去`ABC`的哈希值`h[3]`左移`r - l + 1 = 5 - 4 + 1 = 2`位，即`h[4~5] = h[5] - h[3] * p[2]`。

**代码如下：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    typedef unsigned long long ULL;
    
    const int N = 100010, P = 131;
    
    int n, m;
    char str[N];
    ULL h[N], p[N];
    
    ULL get(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    
    int main()
    {
        scanf("%d%d", &n, &m);
        scanf("%s", str + 1);
    
        p[0] = 1;
        for (int i = 1; i <= n; i ++ )
        {
            h[i] = h[i - 1] * P + str[i];
            p[i] = p[i - 1] * P;
        }
    
        while (m -- )
        {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    
            if (get(l1, r1) == get(l2, r2)) puts("Yes");
            else puts("No");
        }
    
        return 0;
    }
    

> 以上模版和笔记均来源：AcWing的算法基础课  
> 链接：https://www.acwing.com/blog/content/277/