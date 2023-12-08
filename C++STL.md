- [C++STL](#cstl)

# C++STL
```cpp
vector 变⻓数组，倍增的思想
	size() 返回元素个数
	empty() 返回是否为空
	clear() 清空
	front()/back()
	push_back()/pop_back()
	begin()/end()
	[]
	⽀持⽐较运算，按字典序

pair<int, int>
	first, 第⼀个元素
	second, 第⼆个元素
	⽀持⽐较运算，以first为第⼀关键字，以second为第⼆关键字（字典序）

string，字符串
	size()/length() 返回字符串⻓度
	empty()
	clear()
	substr(起始下标，(⼦串⻓度)) 返回⼦串
	c_str() 返回字符串所在字符数组的起始地址

queue, 队列
	size()
	empty()
	push() 向队尾插⼊⼀个元素
	front() 返回队头元素
	back() 返回队尾元素
	pop() 弹出队头元素

priority_queue, 优先队列，默认是⼤根堆
	size()
	empty()
	push() 插⼊⼀个元素
	top() 返回堆顶元素
	pop() 弹出堆顶元素
	定义成⼩根堆的⽅式：priority_queue<int, vector<int>, greater<int>> q;

stack, 栈
	size()
	empty()
	push() 向栈顶插⼊⼀个元素
	top() 返回栈顶元素
	pop() 弹出栈顶元素

deque, 双端队列
	size()
	empty()
	clear()
	front()/back()
	push_back()/pop_back()
	push_front()/pop_front()
	begin()/end()
	[]

set, map, multiset, multimap, 基于平衡⼆叉树（红⿊树），动态维护有序序列
	size()
	empty()
	clear()
	begin()/end()
	++, -- 返回前驱和后继，时间复杂度 O(logn)
	
	set/multiset
		insert() 插⼊⼀个数
		find() 查找⼀个数
		count() 返回某⼀个数的个数
		erase()
			(1) 输⼊是⼀个数x，删除所有x O(k + logn)
			(2) 输⼊⼀个迭代器，删除这个迭代器
		lower_bound()/upper_bound()
			lower_bound(x) 返回⼤于等于x的最⼩的数的迭代器
			upper_bound(x) 返回⼤于x的最⼩的数的迭代器
	map/multimap
		insert() 插⼊的数是⼀个pair
		erase() 输⼊的参数是pair或者迭代器
		find()
		[] 注意multimap不⽀持此操作。 时间复杂度是 O(logn)
		lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
	和上⾯类似，增删改查的时间复杂度是 O(1)
	不⽀持 lower_bound()/upper_bound()， 迭代器的++，--

bitset, 圧位
	bitset<10000> s;
	~, &, |, ^
	>>, <<
	==, !=
	[]

	count() 返回有多少个1
	模板 12
	any() 判断是否⾄少有⼀个1
	none() 判断是否全为0
	set() 把所有位置成1
	set(k, v) 将第k位变成v
	reset() 把所有位变成0
	flip() 等价于~
	flip(k) 把第k位取反

```



