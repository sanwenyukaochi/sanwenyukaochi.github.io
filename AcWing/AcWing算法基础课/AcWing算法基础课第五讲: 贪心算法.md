 

> #### 文章目录
> 
> *   *   [（1）区间问题](#1_2)
>     *   *   [905\. 区间选点](#905__3)
>         *   [908\. 最大不相交区间数量](#908__74)
>         *   [906\. 区间分组](#906__142)
>         *   [907\. 区间覆盖](#907__223)
>     *   [（2）Huffman树](#2Huffman_316)
>     *   *   [148\. 合并果子](#148__317)
>     *   [（3）排序不等式](#3_395)
>     *   *   [913\. 排队打水](#913__396)
>     *   [（4）绝对值不等式](#4_453)
>     *   *   [104\. 货仓选址](#104__454)
>     *   [（5）推公式](#5_521)
>     *   *   [125\. 耍杂技的牛](#125__522)

### （1）区间问题

#### 905\. 区间选点

[题目链接](https://www.acwing.com/problem/content/907/)

给定 `N` 个闭区间 \[ai,bi\]，请你在数轴上选择尽量少的点，使得每个区间内 **至少** 包含一个选出的点。  
输出选择的点的 **最小数量** 。  
位于区间端点上的点也算作区间内。

**输入格式**  
第一行包含整数 `N`，表示区间数。  
接下来 `N` 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

**输出格式**  
输出一个整数，表示所需的点的最小数量。

**数据范围**  
1 ≤ `N` ≤ 105,  
−109 ≤ ai ≤ bi ≤ 109

**输入样例：**  
`3`  
`-1 1`  
`2 4`  
`3 5`

**输出样例：**  
`2`

**解题思路：**

*   将每个区间按右端点从小到大进行排序；
*   从前往后依次枚举每个区间
    *   如果当前区间中已经包含了选出的点，则直接跳过该区间，继续判断下一个区间是否包含选出的点；
    *   如果当前区间中不包含选择的点，也就是说当前区间的左端点`range[i].l`比选出的点`ed`值要大，则更新选择的点，将当前区间的右端点作为新选择的点`ed = range[i].r`。

![在这里插入图片描述](https://img-blog.csdnimg.cn/ade8a0b0a6994d68a91997c6eda81c22.png)

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010;
    
    int n;
    struct Range {
        int l, r;
        bool operator< (const Range &W)const { //重载小于符号
            return r < W.r;
        }
    }range[N];
    
    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
        
        sort(range, range + n); //将区间按右端点从小到大排序
        
        int res = 0, ed = -2e9; // 将选出的点初始化为比区间取值的最小值还小的数
        for (int i = 0; i < n; i++) {
            if (range[i].l > ed) {
                res++;
                ed = range[i].r; //选择新的点，并更新选择的点
            }
        }
        cout << res;
        return 0;
    }
    

* * *

#### 908\. 最大不相交区间数量

[题目链接](https://www.acwing.com/problem/content/910/)

给定 `N` 个闭区间 \[ai,bi\]，请你在数轴上选择若干区间，使得选中的区间之间 **互不相交** （包括端点）。  
输出可选取区间的 **最大数量** 。

**输入格式**  
第一行包含整数 `N`，表示区间数。  
接下来 `N` 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

**输出格式**  
输出一个整数，表示可选取区间的最大数量。

**数据范围**  
1 ≤ `N` ≤ 105,  
−109 ≤ ai ≤ bi ≤ 109

**输入样例：**  
`3`  
`-1 1`  
`2 4`  
`3 5`

**输出样例：**  
`2`

**解题思路：**  
（ 参考 905\. 区间选点 ）

*   将每个区间按右端点从小到大进行排序；
*   从前往后依次枚举每个区间
    *   如果当前区间与选中的区间相交（即当前区间的左端点小于等于选中区间的右端点），则直接跳过该区间，继续判断下一个区间是否与选中的区间相交；
    *   如果当前区间与选中的区间不相交，也就是说当前区间的左端点`range[i].l`比选中区间的右端点`ed`值要大，则更新选中的区间，将当前区间的右端点作为新选中区间的右端点`ed = range[i].r`。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010;
    
    int n;
    struct Range{
        int l, r;
        bool operator< (const Range &W)const {
            return r < W.r;
        }
    }range[N];
    
    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
        
        sort(range, range + n);
        
        int res = 0, ed = -2e9;
        for (int i = 0; i < n; i++) {
            if (ed < range[i].l) {
                res++;
                ed = range[i].r;
            }
        }
        cout << res;
        return 0;
    }
    

* * *

#### 906\. 区间分组

[题目链接](https://www.acwing.com/problem/content/908/)

给定 `N` 个闭区间 \[ai,bi\]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点） **没有交集** ，并使得组数尽可能小。  
输出 **最小组数** 。

**输入格式**  
第一行包含整数 `N`，表示区间数。  
接下来 `N` 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

**输出格式**  
输出一个整数，表示最小组数。

**数据范围**  
1 ≤ N ≤ 105,  
−109 ≤ ai ≤ bi ≤ 109

**输入样例：**  
`3`  
`-1 1`  
`2 4`  
`3 5`

**输出样例：**  
`2`

**解题思路：**

*   首先将所有区间按左端点从小到大进行排序；
*   从前往后依次枚举每个区间，判断能否将当前区间放入某个现有的组中
    *   如果当前区间的左端点`range[i].l`比所有现有的组右端点最小值都还要小，表明当前区间一定会与现有的组有交集，此时则开一个新的组，然后把当前区间放进去；
    *   如果当前区间的左端点`range[i].l`比现有的组右端点最小值大，表明可以把当前区间放入现有右端点最小的那一组中去，并且更新这一组的右端点。

例如：判断以下红色区间能否放入放入现有的组中

![在这里插入图片描述](https://img-blog.csdnimg.cn/c68ac4add2c549de87a3e200c0ef6435.png)

由于当前的区间的左端点比现有的组右端点的[最小值](https://so.csdn.net/so/search?q=%E6%9C%80%E5%B0%8F%E5%80%BC&spm=1001.2101.3001.7020)大，因此可以将它放入现有右端点最小的那一组中去，更新这一组的右端点，然后接着处理下一个区间，处理完这几个区间后如下图：

![在这里插入图片描述](https://img-blog.csdnimg.cn/31e430da5ba64be9903347b2e04a4348.png)

**注意⚠️：**  
可以利用[小根堆](https://so.csdn.net/so/search?q=%E5%B0%8F%E6%A0%B9%E5%A0%86&spm=1001.2101.3001.7020)来存储现有组的右端点，小根堆拥有的右端点的个数即为现有的组的个数，小根堆的根节点即为所有现有的组右端点的最小值。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    #include <queue>
    
    using namespace std;
    
    const int N = 100010;
    
    int n;
    struct Range{
        int l, r;
        bool operator< (const Range &W)const {
            return l < W.l;
        }
    }range[N];
    
    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
        
        sort(range, range + n);
        
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++) {
            if (heap.empty() || heap.top() >= range[i].l) heap.push(range[i].r);
            else {
                heap.pop();
                heap.push(range[i].r);
            }
        }
        cout << heap.size() << endl;
        return 0;
    }
    

* * *

#### 907\. 区间覆盖

[题目链接](https://www.acwing.com/problem/content/909/)

给定 `N` 个闭区间 \[ai,bi\] 以及一个线段区间 `[s,t]`，请你选择尽量少的区间，将指定 **线段区间完全覆盖** 。  
输出 **最少区间数** ，如果无法完全覆盖则输出 `−1`。

**输入格式**  
第一行包含两个整数 `s` 和 `t`，表示给定线段区间的两个端点。  
第二行包含整数 `N`，表示给定区间数。  
接下来 `N` 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

**输出格式**  
输出一个整数，表示所需最少区间数。  
如果无解，则输出 `−1`。

**数据范围**  
1 ≤ `N` ≤ 105,  
−109 ≤ ai ≤ bi ≤ 109,  
−109 ≤ `s` ≤ `t` ≤ 109

**输入样例：**  
`1 5`  
`3`  
`-1 3`  
`2 4`  
`3 5`

**输出样例：**  
`2`

**解题思路：**

*   首先将所有区间按左端点从小到大进行排序；
*   从前往后依次枚举每个区间，在所有左端点小于等于线段区间左端点`s`的区间中，选择右端点最大的区间，然后判断选择的区间右端点是否大于线段区间左端点
    *   若选择区间的右端点小于线段区间的左端点，则表明线段区间的左端点不能被覆盖，则直接结束选择，输出`-1`；
    *   若选择区间的右端点大于线段区间的左端点，则将线段区间左端点`s`更新为选择的区间右端点的位置。
*   重复第2步操作，直到选择的区间右端点值大于等于指定线段区间的右端点的值，表明线段区间全部被覆盖，将结果输出。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010;
    
    int n;
    struct Range{
        int l, r;
        bool operator< (const Range& W)const {
            return l < W.l;
        }
    }range[N];
    
    int main() {
        int st, ed;
        cin >> st >> ed;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;
        
        sort(range, range + n);
        
        int res = 0;
        bool success = false;
        for (int i = 0; i < n; i++) {
            int j = i, r = -2e9;
            while (j < n && range[j].l <= st) {
                r = max(r, range[j].r);
                j++;
            }
            
            if (r < st) {
                res = -1;
                break;
            }
            
            res++;
            if (r >= ed) {
                success = true;
                break;
            }
            
            st = r;
            i = j - 1;
        }
        
        if (!success) res = -1;
        cout << res << endl;
        
        return 0;
    }
    

* * *

### （2）Huffman树

#### 148\. 合并果子

[题目链接](https://www.acwing.com/problem/content/150/)

在一个果园里，达达已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。  
达达决定把所有的果子合成一堆。  
每一次合并，达达可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。  
可以看出，所有的果子经过 `n−1` 次合并之后，就只剩下一堆了。  
达达在合并果子时总共消耗的体力等于每次合并所耗体力之和。  
因为还要花大力气把这些果子搬回家，所以达达在合并果子时要尽可能地节省体力。  
假定每个果子重量都为 `1`，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使达达耗费的体力最少，并输出这个最小的体力耗费值。  
例如有 `3` 种果子，数目依次为 `1`，`2`，`9`。  
可以先将 `1`、`2` 堆合并，新堆数目为 `3`，耗费体力为 `3`。  
接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 `12`，耗费体力为 `12`。  
所以达达总共耗费体力`=3+12=15`。  
可以证明 `15` 为最小的体力耗费值。

**输入格式**  
输入包括两行，第一行是一个整数 `n`，表示果子的种类数。  
第二行包含 `n` 个整数，用空格分隔，第 `i` 个整数 ai 是第 `i` 种果子的数目。

**输出格式**  
输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。  
输入数据保证这个值小于 231。

**数据范围**  
1 ≤ `n` ≤ 10000,  
1 ≤ ai ≤ 20000

**输入样例：**  
`3`  
`1 2 9`

**输出样例：**  
`15`

**解题思路：**

**(贪心,哈夫曼树,堆,优先队列)** `O(nlogn)`

经典哈夫曼树的模型，每次合并重量最小的两堆果子即可。

**时间复杂度**

使用小根堆维护所有果子，每次弹出堆顶的两堆果子，并将其合并，合并之后将两堆重量之和再次插入小根堆中。  
每次操作会将果子的堆数减 `1` ，一共操作 `n−1` 次即可将所有果子合并成`1`堆。每次操作涉及到`2`次堆的删除操作和`1`次堆的插入操作，计算量是 `O(logn)`。因此总时间复杂度是 `O(nlogn)`。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    #include <queue>
    
    using namespace std;
    
    int main() {
        int n;
        cin >> n;
        
        priority_queue<int, vector<int>, greater<int>> heap;
        while (n--) {
            int x;
            cin >> x;
            heap.push(x);
        }
        
        int res = 0;
        while (heap.size() > 1) {
            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();
            res += a + b;
            heap.push(a + b);
        }
        
        cout << res << endl;
        return 0;
    }
    

* * *

### （3）排序不等式

#### 913\. 排队打水

[题目链接](https://www.acwing.com/problem/content/description/915/)

有 `n` 个人排队到 `1` 个水龙头处打水，第 `i` 个人装满水桶所需的时间是 ti，请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？

**输入格式**  
第一行包含整数 `n`。  
第二行包含 `n` 个整数，其中第 `i` 个整数表示第 `i` 个人装满水桶所花费的时间 ti。

**输出格式**  
输出一个整数，表示最小的等待时间之和。

**数据范围**  
1 ≤ n ≤ 105,  
1 ≤ ti ≤ 104

**输入样例：**  
`7`  
`3 6 1 4 2 5 7`

**输出样例：**  
`56`

**解题思路：**

要求安排他们的打水顺序使所有人的等待时间之和最小，则需要安排人们按照打水时间又短到长的顺序依次打水。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    typedef long long LL;
    
    const int N = 100010;
    
    int n;
    int t[N];
    
    int main()
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ) scanf("%d", &t[i]);
    
        sort(t, t + n);
        reverse(t, t + n);
    
        LL res = 0;
        for (int i = 0; i < n; i ++ ) res += t[i] * i;
    
        printf("%lld\n", res);
    
        return 0;
    }
    

### （4）绝对值不等式

#### 104\. 货仓选址

[题目链接](https://www.acwing.com/problem/content/106/)

在一条数轴上有 `N` 家商店，它们的坐标分别为 A1∼AN。  
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。  
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

**输入格式**  
第一行输入整数 `N`。  
第二行 `N` 个整数 A1∼AN。

**输出格式**  
输出一个整数，表示距离之和的最小值。

**数据范围**  
1 ≤ `N` ≤ 100000,  
0 ≤ Ai ≤ 40000

**输入样例：**  
`4`  
`6 2 9 1`

**输出样例：**  
`12`

**解题思路：**

假设数轴上的`n`家商店的坐标为 X1、X2、X3、… 、 Xn ，货仓的坐标为 `X` ，则货仓到每家商店的距离之和`f(x)`可表示为

`f(x)` = |X1 \- `X`| \+ |X2 \- `X`| \+ … \+ |Xn \- `X`|  
`f(x)` = ( |X1 \- `X`| \+ |Xn \- `X`| ) \+ ( |X2 \- `X`| \+ |Xn-1 \- `X`| ) \+ …

由于 |X1 \- `X`| \+ |Xn \- `X`| 为 X1 到 `X` 的距离与 Xn 到 `X` 的距离之和，其最小值为 Xn \- X1，即`X`位于 X1 与 Xn之间时取到最小值。同理可得到：

`f(x)` >= Xn \- X1 \+ Xn-1 \- X2 \+ …

由此可知，当货仓的坐标 `X`为`n`家商店坐标的中位数时，距离之和最小。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 100010;
    
    int n;
    int q[N];
    
    int main()
    {
        scanf("%d", &n);
    
        for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    
        sort(q, q + n);
    
        int res = 0;
        for (int i = 0; i < n; i ++ ) res += abs(q[i] - q[n / 2]);
    
        printf("%d\n", res);
    
        return 0;
    }
    

* * *

### （5）推公式

#### 125\. 耍杂技的牛

[题目链接](https://www.acwing.com/problem/content/127/)

农民约翰的 `N` 头奶牛（编号为 `1..N`）计划逃跑并加入马戏团，为此它们决定练习表演杂技。  
奶牛们不是非常有创意，只提出了一个杂技表演：

叠罗汉，表演时，奶牛们站在彼此的身上，形成一个高高的垂直堆叠。  
奶牛们正在试图找到自己在这个堆叠中应该所处的位置顺序。  
这 `N` 头奶牛中的每一头都有着自己的重量 Wi 以及自己的强壮程度 Si。  
一头牛支撑不住的可能性取决于它头上所有牛的总重量（不包括它自己）减去它的身体强壮程度的值，现在称该数值为 **风险值** ，风险值越大，这只牛撑不住的可能性越高。

您的任务是确定奶牛的排序，使得所有奶牛的风险值中的最大值尽可能的小。

**输入格式**  
第一行输入整数 `N`，表示奶牛数量。  
接下来 `N` 行，每行输入两个整数，表示牛的重量和强壮程度，第 `i` 行表示第 `i` 头牛的重量 Wi 以及它的强壮程度 Si。

**输出格式**  
输出一个整数，表示最大风险值的最小可能值。

**数据范围**  
1 ≤ `N` ≤ 50000,  
1 ≤ Wi ≤ 10,000,  
1 ≤ Si ≤ 1,000,000,000

**输入样例：**  
`3`  
`10 3`  
`2 5`  
`3 3`

**输出样例：**  
`2`

**解题思路：**

**(贪心)**  
与国王游戏的贪心策略相似， 我们先分析每头牛的危险值 = 它头上牛的 W (重量值)和 - 自身的 S (强壮值)，要使每头牛的危险值最小，显然是与 W 和 S 同时相关，从上至下按每头牛的 Wi \+ Si 从小到大的顺序进行排序，风险值中的最大值一定是最小的。

**C++代码：**

    #include <iostream>
    #include <algorithm>
    
    using namespace std;
    
    const int N = 500010;
    int n;
    
    struct Range{
        int w, s;
        bool operator<(const Range &W)const { // 按照w + s的总和从小到大排序
            return (w + s) < (W.w + W.s);
        }
    }range[N];
    
    int main() {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> range[i].w >> range[i].s;
        
        sort(range, range + n);
        
        for (int i = 1; i < n; i++) range[i].w += range[i - 1].w; // 求w的前n项和
        
        int res = -range[0].s; // 风险值初始化为最上面那头牛的风险值
        for (int i = 1; i < n; i++) res = max(res, range[i - 1].w - range[i].s); // 求风险值中的最大值
        cout << res << endl;
        
        return 0;
    }