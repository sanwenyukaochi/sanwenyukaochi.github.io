 

> 笔记参考[AcWing算法基础课](https://so.csdn.net/so/search?q=AcWing%E7%AE%97%E6%B3%95%E5%9F%BA%E7%A1%80%E8%AF%BE&spm=1001.2101.3001.7020)  
> 
> #### 文章目录
> 
> *   *   *   [1\. 排序](#1__2)
>         *   *   [算法一：快速排序——分治](#_4)
>             *   *   [快速排序算法模版](#_14)
>             *   [算法二：归并排序——分治](#_29)
>             *   *   [归并排序算法模版](#_35)
>         *   [2\. 二分法查找](#2__58)
>         *   *   [二分法主要思想：](#_59)
>             *   *   [整数二分算法模版](#_77)
>                 *   [浮点数二分算法模板](#_106)

#### 1\. 排序

这里主要讲解快速排序和[归并排序](https://so.csdn.net/so/search?q=%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F&spm=1001.2101.3001.7020)，这也是算法题中运用最多的两类排序算法。

##### 算法一：快速排序——分治

对数组q\[\]的区间`[l, r]`中的元素进行排序

![在这里插入图片描述](https://img-blog.csdnimg.cn/6bef20131b5345b8bf93edf62035b063.png)  
假定`x`为分界点，则快速排序的步骤如下：

1.  确定分界点`x`: `q[l]`、`q[r]`、`q[(l + r) / 2]`或者随机选择分界点；
2.  调整区间： **难点**  
    ![请添加图片描述](https://img-blog.csdnimg.cn/641fc38f6b7f405686669e121a461b87.jpeg)  
    保证数组中位于x左侧的元素小于等于x，位于x右侧的元素大于等于x；
3.  分别递归左右两个区间。

###### 快速排序算法模版

模版题[AcWing 785.快速排序](https://www.acwing.com/problem/content/787/)
```cpp
    void quick_sort(int q[], int l, int r) {
    	if (l >= r) return;
    	int x = q[l], i = l - 1, j = r + 1;
    	while (i < j) {
    		do i++; while (q[i] < x);
    		do j--; while (q[j] > x);
    		if (i < j) swap(q[i], q[j]);
    	}
    	quick_sort(q, l, j), quick_sort(q, j + 1, r);
    }
```

##### 算法二：归并排序——分治

![请添加图片描述](https://img-blog.csdnimg.cn/af25baf7f1d7429ba69f64b725eb2261.png)  
**归并排序步骤如下：**

1.  确定分界点：`mid = (l + r) / 2`;
2.  对左区间`left`和右区间`right`分别进行递归排序；
3.  归并：用两个指针分别指向左右区间的起始位置，比较`left`区间和`right`区间的最小值，将得到的最小值临时存放于数组`tmp[]`中，并向后移动这个指向最小值的指针。通过分别移动指向左右两个区间的指针，最终将两个区间合二为一成`tmp[]`。（注意：若两个指针所指元素相同，默认将第一个指针向后移动）

###### 归并排序算法模版

模版题[AcWing 787.归并排序](https://www.acwing.com/problem/content/789/)
```cpp
    void merge_sort(int q[], int l, int r)
    {
        if (l >= r) return;
    
        int mid = l + r >> 1;
        merge_sort(q, l, mid);
        merge_sort(q, mid + 1, r);
    
        int k = 0, i = l, j = mid + 1;
        while (i <= mid && j <= r)
            if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
            else tmp[k ++ ] = q[j ++ ];
    
        while (i <= mid) tmp[k ++ ] = q[i ++ ];
        while (j <= r) tmp[k ++ ] = q[j ++ ];
    
        for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
    }
```

#### 2\. 二分法查找

##### 二分法主要思想：

首先确定整个区间的中点`mid`，将区间划分为左右两个区间，然后比较`mid`与目标值`t`的大小，通过`mid`所处位置来确定下一个查找的区间，选择目标值`t`所在的区间进行下一次查找（也就是说将`mid`作为下一次查找区间的端点，不断缩小查找目标值的区间，每次缩小查找的范围时，都必须将目标值`t`包含在区间中，最终区间的左右端点值相等，此时就找到了目标值`t`）  
![请添加图片描述](https://img-blog.csdnimg.cn/c0f9beb9f98b4b96b67f594c52b032a8.png)  
二分法查找根据`mid`与目标值`t`的相对位置不同，分为以下两种情况：

第一种情况：
```cpp
    mid = (l + r + 1) / 2;  // 第一种情况：mid位于[l, t]时，check(mid)为真
    if (check(mid) == true)  l = mid;  // 此时mid位于[l, t]，下一次查找时，将区间缩小为[mid, r]
    else r = mid - 1;  // 此时mid位于(t, r]，下一次查找时，将区间缩小为[l, mid - 1]
```

第二种情况：
```cpp
    mid = (l + r ) / 2;  // 第二种情况：mid位于[t, r]时，check(mid)为真
    if (check(mid) == true)  r = mid;  // 此时mid位于[t, r]，下一次查找时，将区间缩小为[l, mid]
    else l = mid + 1;  // 此时mid位于[l, t)，下一次查找时，将区间缩小为[mid + 1, r]
```

⚠️注意：`mid`位于目标值`t`的左侧或右侧时，`mid`的取值会有所不同，主要是为了防止遍历发生死循环。

###### 整数二分算法模版

模版题[AcWing 789.数的范围](https://www.acwing.com/problem/content/791/)
```cpp
    bool check(int x) {/* ... */} // 检查x是否满足某种性质
    
    // 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
    int bsearch_1(int l, int r)
    {
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;    // check()判断mid是否满足性质
            else l = mid + 1;
        }
        return l;
    }
    // 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
    int bsearch_2(int l, int r)
    {
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
```

###### 浮点数二分算法模板

*   相比整数二分，浮点数二分无需考虑边界问题，比较简单。  
    当二分的区间足够小时，可以认为已经找到了答案，如当r - l < 1e-8（根据经验，如果结果要求保留 6 位小数，则取1e-8），停止二分。  
    或者直接迭代一定的次数，比如循环100次后停止二分。

模板题[AcWing 790. 数的三次方根](https://www.acwing.com/problem/content/792/)
```cpp
    bool check(double x) {/* ... */} // 检查x是否满足某种性质
    
    double bsearch_3(double l, double r)
    {
        const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        return l;
    }
```

> 参考资料：AcWing的算法基础课  
> 链接：https://www.acwing.com/blog/content/277/