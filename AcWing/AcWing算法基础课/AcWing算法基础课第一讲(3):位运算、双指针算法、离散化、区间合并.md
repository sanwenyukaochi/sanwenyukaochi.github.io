 

> #### 文章目录
> 
> *   *   *   [1\. 位运算](#1__1)
>         *   *   [模板题1](#1_13)
>             *   [模板题2 AcWing 801. 二进制中1的个数](#2_AcWing_801_1_28)
>         *   [2\. 双指针算法](#2__67)
>         *   *   [模板题1 AcWing 799. 最长连续不重复子序列](#1_AcWing_799__82)
>             *   [模板题2 AcWing 800. 数组元素的目标和](#2_AcWing_800__121)
>         *   [3.离散化](#3_169)
>         *   *   [模板题 AcWing 802. 区间和](#_AcWing_802__191)
>         *   [4.区间合并](#4_276)
>         *   *   [模板题 AcWing 803. 区间合并](#_AcWing_803__303)

#### 1\. [位运算](https://so.csdn.net/so/search?q=%E4%BD%8D%E8%BF%90%E7%AE%97&spm=1001.2101.3001.7020)

给定一个数字`n`，求`n`的二进制表示中第`k`位数字。  
思路：比如`n = 15`，`n`的二进制可表示为`1111`  
1\. 先把第`k`位移到最后一位：`n >> k`(n从第0位开始)  
2\. 然后根据个位的数字来确定第`k`位的数字：`x & 1`  
将以上两步合并，就是`n >> k & 1`

**位运算模版**

    求n的第k位数字: n >> k & 1
    返回n的最后一位1：lowbit(n) = n & -n
    

##### 模板题1

输入一个正整数n = 10，将n的二进制表示输出。  
**输出格式**  
共一行，包含n的二进制表示。

    #include <iostream>
    
    using namespace std;
    
    int main() {
        int n = 10;
        for (int k = 3; k >= 0; k--) cout << (n >> k & 1);
        return 0;
    }
    

##### 模板题2 [AcWing](https://so.csdn.net/so/search?q=AcWing&spm=1001.2101.3001.7020) 801\. 二进制中1的个数

给定一个长度为 n 的数列，请你求出数列中每个数的二进制表示中 1 的个数。  
**输入格式**  
第一行包含整数 n。  
第二行包含 n 个整数，表示整个数列。  
**输出格式**  
共一行，包含 n 个整数，其中的第 i 个数表示数列中的第 i 个数的二进制表示中 1 的个数。  
**数据范围**  
1≤n≤100000,  
0≤数列中元素的值≤109  
**输入样例：**  
5  
1 2 3 4 5  
**输出样例：**  
1 1 2 1 2

    #include <iostream>
    using namespace std;
    // 返回x的最后一位1
    int lowbit(int x) {
        return x & (-x); //相当于 x & (~x + 1)
    }
    
    int main() {
        int n;
        scanf("%d", &n);
        while (n--) {
            int x, res = 0;
            scanf("%d", &x);
            while (x) {
                x -= lowbit(x);
                res++;
            }
            printf("%d ", res);
        }
        return 0;
    }
    

#### 2\. [双指针算法](https://so.csdn.net/so/search?q=%E5%8F%8C%E6%8C%87%E9%92%88%E7%AE%97%E6%B3%95&spm=1001.2101.3001.7020)

若使用朴素做法的时间复杂度为：O(n2)，那么使用双指针算法，可将时间复杂度降为：O(n)。  
常见问题分类：  
(1) 对于一个序列，用两个指针维护一段区间  
(2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作

**双指针算法模版**

    for (int i = 0, j = 0; i < n; i ++ )
    {
        while (j < i && check(i, j)) j ++ ;
    
        // 具体问题的逻辑
    }
    

##### 模板题1 AcWing 799. 最长连续不重复子序列

给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。  
**输入格式**  
第一行包含整数 n。  
第二行包含 n 个整数（均在 0∼105 范围内），表示整数序列。  
**输出格式**  
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。  
**数据范围**  
1≤整数长度≤100000  
**输入样例：**  
5  
1 2 2 3 5  
**输出样例：**  
3

    #include <iostream>
    
    using namespace std;
    
    const int N = 100010;
    int n, q[N], cnt[N];
    
    int main() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &q[i]);
        int res = 0;
        for (int i = 0, j = 0; i < n; i ++) {
            cnt[q[i]]++;
            while (cnt[q[i]] > 1 && j < i) {
                cnt[q[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        cout << res << endl;
        return 0;
    }
    

##### 模板题2 AcWing 800. 数组元素的目标和

给定两个升序排序的有序数组 A 和 B，以及一个目标值 x。  
数组下标从 0 开始。  
请你求出满足 A\[i\]+B\[j\]=x 的数对 (i,j)。  
数据保证有唯一解。  
**输入格式**  
第一行包含三个整数 n,m,x，分别表示 A 的长度，B 的长度以及目标值 x。  
第二行包含 n 个整数，表示数组 A。  
第三行包含 m 个整数，表示数组 B。  
**输出格式**  
共一行，包含两个整数 i 和 j。  
**数据范围**  
数组长度不超过105。  
同一数组内元素各不相同。  
1≤数组元素≤109  
**输入样例：**  
4 5 6  
1 2 4 7  
3 4 6 8 9  
**输出样例：**  
1 1

    #include <iostream>
    
    using namespace std;
    
    const int N = 1e5 + 10;
    
    int n, m, x;
    int a[N], b[N];
    
    int main()
    {
        scanf("%d%d%d", &n, &m, &x);
        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
        for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);
    
        for (int i = 0, j = m - 1; i < n; i ++ )
        {
            while (j >= 0 && a[i] + b[j] > x) j -- ;
            if (j >= 0 && a[i] + b[j] == x) cout << i << ' ' << j << endl;
        }
    
        return 0;
    }
    

#### 3.离散化

有许多数分布在数轴上，数的取值范围很广，但是这些数的个数相对来说不是很多，要求对数轴上某个区间上的数进行求和等操作，可使用离散化模版，将数值映射到下标。

**离散化模版**

    vector<int> alls; // 存储所有待离散化的值
    sort(alls.begin(), alls.end()); // 将所有值排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素
    
    // 二分求出x对应的离散化的值
    int find(int x) // 找到第一个大于等于x的位置
    {
        int l = 0, r = alls.size() - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (alls[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r + 1; // 映射到1, 2, ...n
    }
    

##### 模板题 AcWing 802. 区间和

假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。  
现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。  
接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 \[l,r\] 之间的所有数的和。  
**输入格式**  
第一行包含两个整数 n 和 m。  
接下来 n 行，每行包含两个整数 x 和 c。  
再接下来 m 行，每行包含两个整数 l 和 r。  
**输出格式**  
共 m 行，每行输出一个询问中所求的区间内数字和。  
**数据范围**  
−109≤x≤109,  
1≤n,m≤105,  
−109≤l≤r≤109,  
−10000≤c≤10000  
**输入样例：**  
3 3  
1 2  
3 6  
7 5  
1 3  
4 6  
7 8  
**输出样例：**  
8  
0  
5

    #include <iostream>
    #include <vector>
    #include <algorithm>
    
    using namespace std;
    const int N = 300010; //n次插入和m次查询相关数据量的上界
    
    typedef pair<int, int> PII;
    vector<PII> add, query; //存储插入和询问操作的数据
    vector<int> alls; //存储所有待离散化的值（所有与插入和查询有关的），将待离散化的值映射到alls的下标
    
    int a[N], s[N]; // a[N]用来表示离散化后的数组,s[N]用来表示前缀和
    int n, m;
    //二分求出x对应的离散化的值
    int find(int x) { //找到第一个大于等于x的位置
        int l = 0, r = alls.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (alls[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return r + 1;
    }
    
    int main() {
        cin >> n >> m;
        while (n--) {
            int x, c;
            cin >> x >> c;
            add.push_back({x, c});
            alls.push_back(x);
        }
        while (m--) {
            int l, r;
            cin >> l >> r;
            query.push_back({l, r});
            alls.push_back(l);
            alls.push_back(r);
        }
        //排序，去重
        sort(alls.begin(), alls.end()); //将所有待离散化的值进行排序
        alls.erase(unique(alls.begin(), alls.end()), alls.end()); 去掉重复元素
        //处理插入
        for (auto item : add) {
            int x = find(item.first);
            a[x] += item.second;
        }
        //处理前缀和
        for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];
        //处理询问
        for (auto item : query) {
            int l = find(item.first), r = find(item.second);
            cout << s[r] - s[l - 1] << endl;
        }
        return 0;
    }
    

#### 4.区间合并

给定 n 个区间 \[li,ri\]，要求合并所有有交集的区间。  
思路：可以将n个区间先按左端点排序，维护一个区间，并将维护区间与后面一个区间进行三种情况的比较（1.后一个区间包含于维护区间；2.后一个区间与维护区间部分相交；3.两个区间不相交），若后一个区间和当前维护的区间不相交时，需要将当前维护的区间存储到结果数组里，并将后一个区间作为新的维护区间，继续以上有关操作。

**区间合并模版**

    // 将所有存在交集的区间合并
    void merge(vector<PII> &segs)
    {
        vector<PII> res;
    
        sort(segs.begin(), segs.end());
    
        int st = -2e9, ed = -2e9;
        for (auto seg : segs)
            if (ed < seg.first)
            {
                if (st != -2e9) res.push_back({st, ed});
                st = seg.first, ed = seg.second;
            }
            else ed = max(ed, seg.second);
    
        if (st != -2e9) res.push_back({st, ed});
    
        segs = res;
    }
    

##### 模板题 AcWing 803. 区间合并

给定 n 个区间 \[li,ri\]，要求合并所有有交集的区间。  
注意如果在端点处相交，也算有交集。  
输出合并完成后的区间个数。  
例如：\[1,3\] 和 \[2,6\] 可以合并为一个区间 \[1,6\]。  
**输入格式**  
第一行包含整数 n。  
接下来 n 行，每行包含两个整数 l 和 r。  
**输出格式**  
共一行，包含一个整数，表示合并区间完成后的区间个数。  
**数据范围**  
1≤n≤100000,  
−109≤li≤ri≤109  
**输入样例：**  
5  
1 2  
2 4  
5 6  
7 8  
7 9  
**输出样例：**  
3

    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;
    
    typedef pair<int, int> PII;
    vector<PII> segs;
    
    // 将所有存在交集的区间合并
    void merge(vector<PII> &segs) {
        vector<PII> res;
        sort(segs.begin(), segs.end()); //按左端点排序
        int st = -2e9, ed = -2e9; //初始化st和ed，ed代表维护区间的结尾，st代表维护的区间开头
        for (auto item : segs) {
            if (ed < item.first) { //两个区间无法合并的情况
                if (ed != -2e9) res.push_back({st, ed}); //把维护的区间放进res数组
                st = item.first, ed = item.second; //更新维护的区间
            }
            else //两个区间可以合并的情况
                ed = max(ed, item.second);
        }
        if (ed != -2e9) res.push_back({st, ed}); //将最后一个维护区间放进res数组中
        segs = res;
    }
    
    int main() {
        int n;
        cin >> n;
        while (n--) {
            int l, r;
            cin >> l >> r;
            segs.push_back({l, r});
        }
        merge(segs);
        cout << segs.size() << endl;
        return 0;
    }
    

> 以上模版和笔记均来源：AcWing的算法基础课  
> 链接：https://www.acwing.com/blog/content/277/